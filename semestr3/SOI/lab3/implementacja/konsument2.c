#include "buffer.h"
#include <stdio.h>

/*
* KONSUMENT
*
*/
int main(int argc, char* argv[]){
buf_initialise(atoi(argv[1]),atoi(argv[2]));
usleep(2000000);
while(1){
	buf_pop_front();
}

return 0;
}
