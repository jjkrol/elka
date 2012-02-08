#include <iostream>
#include <cstdlib>
#include "disk.h"

int main(int argc, char * argv[]){
	std::cout<<"Start"<<std::endl;
	VirtualDisk * disk = new VirtualDisk(4);
	disk->copyFromMinixToVirtual("test");
	disk->copyFromMinixToVirtual("test2");
	disk->removeFile("test");
	disk->copyFromMinixToVirtual("test3");
	disk->listFiles();
	system("mv test3 test8");
	disk->copyFromVirtualToMinix("test3");
	disk->copyFromMinixToVirtual("test3");
	delete disk;

}
