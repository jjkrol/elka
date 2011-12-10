#include "buffer.h"
#include <stdio.h>

/*
* PRODUCENT
*
*/

int main(int argc, char* argv[]){
if (buf_initialise(atoi(argv[1]),atoi(argv[2]))<0) exit(1);

srand(time(NULL));
queue_clear();
while(1){
buf_push(rand()%100);
}

return 0;
}
