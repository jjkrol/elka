#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class VirtualDisk {
	public:
		VirtualDisk (int sizeInKilobytes);
		~VirtualDisk ();
	 	void copyFromMinixToVirtual(char * );
		void	listFiles();
		void	removeFile(char *);
		void	copyFromVirtualToMinix(char * );
		void	showMap();

	private:
		typedef struct InfoBlock{
			int diskSize;
			int freeSpace;
			int fileCount;
			int dataOffset;
		} InfoBlack;
		typedef struct FatItem{
			int nextItem;
		} FatItem;

		typedef struct FileDescriptor{
			char * filename;
			int size;
			int firstBlock;	
		} FileDescriptor;
		void	createEmptyFile();
		void	fillFileWithZeros(int);
		void	writeInfoBlock();
		void	readInfoBlock();
		void	writeFatTable();
		void	readFatTable();
		void	calculateFreeSpace();
		void	initialiseFat();
		void	readFileList();
		void	addFileDescriptor(FileDescriptor);
		void	printFat();
		char * 	readFromBlock(int);
		char * 	readBlock(int);
		int 	calculateBlockOffset(int);
		int 	calculateAvailableBlocks(int);
		int 	findFreeBlock();
		int		getFileFirstBlock(char *);
		int		getFileSize(char *);
		int	removeFileFromList(char *);
		void	writeFileList();

		fstream	mainFile;
		int diskSizeInKilobytes;
		int freeSpace;
		int fileCount;
		int dataOffset;
		int fatTableOffset;
		int firstBlockOffset;
		int fatSize;
		FatItem * fileAllocationTable;	
		FileDescriptor * fileList;

};
