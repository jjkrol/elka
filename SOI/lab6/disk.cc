#include "disk.h"
#include <cstring>
#include <cstdlib>

#define BLOCK_SIZE 16
using namespace std;
VirtualDisk::VirtualDisk(int sizeInKilobytes):
		diskSizeInKilobytes(sizeInKilobytes),
		freeSpace(sizeInKilobytes),
		fileCount(0)
{
		fileList = (FileDescriptor *)malloc(sizeof(FileDescriptor));
		if( access( "virtualdisk.bin", F_OK ) != -1 ) {
				std::cout<<"File exists, size ignored"<<std::endl;
				mainFile.open("virtualdisk.bin", ios::out | ios::in | ios::binary);
				readInfoBlock();
				readFatTable();
				readFileList();
		} else {
		int sizeInBytes = 1024*sizeInKilobytes;
		fatSize = calculateAvailableBlocks(sizeInBytes);
				createEmptyFile();
				mainFile.open("virtualdisk.bin", ios::out | ios::in | ios::binary);
				fillFileWithZeros(sizeInBytes);		
				writeInfoBlock();
				initialiseFat();
				writeFatTable();
		}
}

VirtualDisk::~VirtualDisk(){
		mainFile.close();
}


void VirtualDisk::createEmptyFile(){
		std::cout<<"Creating a file"<<std::endl;
		ofstream tempFileHandle;
		tempFileHandle.open("virtualdisk.bin", ios::out | ios::binary);
		tempFileHandle.close();
}

void VirtualDisk::fillFileWithZeros(int sizeInBytes){
		int number = 0;
		for (int i = 0; i < sizeInBytes/sizeof(int); i++) {
				mainFile.write((char *)(&number), sizeof(int) );
		}
}

void VirtualDisk::writeInfoBlock(){
		InfoBlock info;
		info.diskSize = diskSizeInKilobytes;
		info.freeSpace = 0;//freeSpace;
		info.fileCount = fileCount;
		info.dataOffset = dataOffset;
		mainFile.seekp(0);
		mainFile.write((char*)(&info), sizeof(InfoBlock));
}
void VirtualDisk::readInfoBlock(){
std::cout<<"Reading info block"<<std::endl;
		InfoBlock info;
		mainFile.seekg(0);
		mainFile.read((char*)(&info), sizeof(InfoBlock));
		diskSizeInKilobytes = info.diskSize;
		fileCount = info.fileCount;
		dataOffset = info.dataOffset; 
		fatSize = (dataOffset - sizeof(InfoBlock))/sizeof(FatItem);
		std::cout<<"fat size "<<fatSize<<std::endl;
		std::cout<<"dane: "<<diskSizeInKilobytes<<" "<<fileCount<<" "<<dataOffset<<" "<<info.freeSpace<<std::endl;
}

void VirtualDisk::initialiseFat(){
		fileAllocationTable = new FatItem[fatSize];
		fatTableOffset = sizeof(InfoBlock);	
		dataOffset = fatTableOffset + fatSize * sizeof(FatItem);
		for (int i = 0; i < fatSize; i++) {
				fileAllocationTable[i].nextItem=-1;
		}
		fileAllocationTable[0].nextItem=-2; // reserved for descriptors
}

void VirtualDisk::writeFatTable(){
		mainFile.seekp(fatTableOffset);
		for (int i = 0; i < fatSize; i++) {
				mainFile.write((char*)(&fileAllocationTable[i]), sizeof(FatItem));
		}
}
void VirtualDisk::readFatTable(){
	std::cout<<"Reading fat table"<<std::endl;
	initialiseFat();
		mainFile.seekg(fatTableOffset);
		for (int i = 0; i < fatSize; i++) {
				mainFile.read((char*)(&fileAllocationTable[i]), sizeof(FatItem));
		}

}
void VirtualDisk::printFat(){
	for (int i = 0; i < fatSize; i++) {
		std::cout<<"tablica["<<i<<"]="<<fileAllocationTable[i].nextItem<<std::endl;
	}
}

void VirtualDisk::writeFileList(){
		int bufferSize = sizeof(FileDescriptor)*(fileCount+1);
		int freeBlockNumber, previousFreeBlock, freeBlockOffset;
		char * memblock = (char *)malloc(BLOCK_SIZE);
		char * buffer = (char *) malloc(bufferSize);
		int bufferSizeInBlocks = bufferSize/BLOCK_SIZE +2; //TODO
		std::cout<<"File list size in blocks "<<bufferSizeInBlocks<<" size in bytes "<<bufferSize<<std::endl;
		memcpy(buffer, fileList, bufferSize);
		FileDescriptor * lista = (FileDescriptor *)buffer;
		for (int i = 0; i < bufferSizeInBlocks; i++) {
			if(i==0) freeBlockNumber = 0;
			else{ 
					freeBlockNumber = findFreeBlock();

				if(freeBlockNumber == -1){
						std::cout<<"brak wolnych blokow"<<std::endl;
						return;
				}
				fileAllocationTable[previousFreeBlock].nextItem = freeBlockNumber;
			}
				fileAllocationTable[freeBlockNumber].nextItem = -2;
				previousFreeBlock = freeBlockNumber;

				freeBlockOffset = calculateBlockOffset(freeBlockNumber);
				memset(memblock, 0, BLOCK_SIZE);
				memcpy(memblock, buffer + i*sizeof(FileDescriptor), sizeof(FileDescriptor));
				mainFile.seekp(freeBlockOffset);
				mainFile.write(memblock, BLOCK_SIZE);
		}
		std::cout<<"File list written"<<std::endl;
		writeFatTable();
}

void VirtualDisk::readFileList(){
std::cout<<"Reading file list"<<std::endl;
		int blockNumber, fileSize;
		char * listData = readFromBlock(0);
		std::cout<<"listData "<<((FileDescriptor *)listData)[0].filename<<std::endl;
		int listSize = (fileCount+1)*sizeof(FileDescriptor); 
		fileList = (FileDescriptor *) realloc(fileList, listSize);
		std::cout<<"size: "<<listSize<<std::endl;
		memcpy(fileList, listData, listSize);
		std::cout<<"File list read:"<<std::endl;
		listFiles();
}

void VirtualDisk::listFiles(){
		std::cout<<"--------Listing files-----------"<<std::endl;
std::cout<<"file count: "<<fileCount<<std::endl;
	for(int i=0; i<fileCount; i++){
		std::cout<<fileList[i].filename<<"\t "<<fileList[i].firstBlock<<"\t\t"<<fileList[i].size<<std::endl;
	}
	std::cout<<"---------Files listed------------"<<std::endl;
}

char * VirtualDisk::readFromBlock(int blockNumber){
		char * singleBlock;
		char * fullBlock=NULL;
		int i=1;
		while(blockNumber>=0){
				fullBlock = (char *) realloc(fullBlock, BLOCK_SIZE*i);
				singleBlock = readBlock(calculateBlockOffset(blockNumber));
				memcpy(fullBlock+BLOCK_SIZE*(i-1), singleBlock, BLOCK_SIZE);
				delete singleBlock;
				blockNumber = fileAllocationTable[blockNumber].nextItem;
			   i++;	
		}
		return fullBlock;
}

char * VirtualDisk::readBlock(int blockOffset){
		char * singleBlock = new char[BLOCK_SIZE];
		mainFile.seekg(blockOffset, ios::beg);
		mainFile.read(singleBlock, BLOCK_SIZE);
		return singleBlock;
}

int VirtualDisk::calculateAvailableBlocks(int sizeInBytes){
		int availableSpace = sizeInBytes-sizeof(InfoBlock);
		int pairSize = sizeof(FatItem)+BLOCK_SIZE;
		int blocksCount = availableSpace/pairSize;
		return blocksCount;
}

void VirtualDisk::copyFromMinixToVirtual(char * filename){
		char * memblock = new char[BLOCK_SIZE]; 
		int freeBlockNumber;
		int freeBlockOffset;
		int previousFreeBlock=-1;
		int size = 0;
		ifstream source(filename, ios::binary);

		if(getFileFirstBlock(filename) != -1){
				std::cout<<"Plik juz istnieje"<<std::endl;
				return;
		}

		FileDescriptor descriptor;
		descriptor.filename = filename;
	
		while(!source.eof()){
				freeBlockNumber = findFreeBlock();
				if(freeBlockNumber == -1){
						std::cout<<"brak wolnych blokow, nie mozna zapisac pliku"<<std::endl;
						return;
				}
				if(previousFreeBlock != -1){
						fileAllocationTable[previousFreeBlock].nextItem = freeBlockNumber;
				}
				else{
					descriptor.firstBlock = freeBlockNumber;
				}

				fileAllocationTable[freeBlockNumber].nextItem = -2;
				previousFreeBlock = freeBlockNumber;

				freeBlockOffset = calculateBlockOffset(freeBlockNumber);

				memset(memblock, 0, BLOCK_SIZE);
				source.read(memblock, BLOCK_SIZE);
				mainFile.seekp(freeBlockOffset);
				mainFile.write(memblock, BLOCK_SIZE);

				size++;
		}
		descriptor.size = size;
		source.close();
		addFileDescriptor(descriptor);
		writeFatTable();
		writeFileList();
		writeInfoBlock();
		std::cout<<"File "<<filename<<" added at block "<<descriptor.firstBlock<<std::endl;
}

int VirtualDisk::calculateBlockOffset(int number){
	return number*BLOCK_SIZE + dataOffset;
}

void VirtualDisk::addFileDescriptor(FileDescriptor descriptor){
		fileList[fileCount++] = descriptor;
		fileList = (FileDescriptor *) realloc(fileList, (fileCount+1)*sizeof(FileDescriptor));
}


int VirtualDisk::getFileSize(char * filename){
		int i = 0;
	while(i<fileCount && fileList[i].filename!=filename){
		i++;
	}
	if(i == fileCount)
			return -1;
	else
			return fileList[i].size;
}

int VirtualDisk::getFileFirstBlock(char * filename){
		int i = 0;
	while(i<fileCount && fileList[i].filename!=filename){
		i++;
	}
	if(i == fileCount)
			return -1;
	else
			return fileList[i].firstBlock;
}

int VirtualDisk::removeFileFromList(char * filename){
		int i=0;
	while(i<fileCount && fileList[i].filename!=filename){
		i++;
	}
	if(i == fileCount)
			return -1;
	else{
		for (int j = i; j < fileCount-1; j++) {
			fileList[i] = fileList[i+1];	
		}
		fileCount--;
	}
	writeFileList();
}

void VirtualDisk::removeFile(char * filename){
	int blockNumber = getFileFirstBlock(filename); 
	int prevBlockNumber = -1;
	if (blockNumber == -1) return;
	while(blockNumber >=0){
			prevBlockNumber = blockNumber;
			blockNumber = fileAllocationTable[blockNumber].nextItem;
			if(prevBlockNumber >=0){
					fileAllocationTable[prevBlockNumber].nextItem = -1;
			}
	}
	removeFileFromList(filename);
	writeFatTable();
	std::cout<<"File "<<filename<<" removed"<<std::endl;

}

int VirtualDisk::findFreeBlock(){
		int i=0;
		while(fileAllocationTable[i].nextItem!=-1 && i<fatSize){
				i++;
		}
		return (i==fatSize)?-1:i;
}


void	VirtualDisk::copyFromVirtualToMinix(char * filename){
		int blockNumber, fileSize;
		blockNumber = getFileFirstBlock(filename);
		if (blockNumber == -1) return;
		char * fileData = readFromBlock(blockNumber);
		fileSize = getFileSize(filename);

		ofstream target(filename, ios::binary);
		target.write(fileData,fileSize*BLOCK_SIZE);
		target.close();
		free(fileData);
}


