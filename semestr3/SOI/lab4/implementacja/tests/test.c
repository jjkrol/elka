#include "buffer.h"
#include <stdio.h>

/*
* KONSUMENT
*
*/
int main(int argc, char* argv[]){
buf_initialise(atoi(argv[1]),atoi(argv[2]));
int i=0;
while(i<200){
	i++;
	queue_list();
	usleep(50000);
}

buf_deact();
return 0;
}
