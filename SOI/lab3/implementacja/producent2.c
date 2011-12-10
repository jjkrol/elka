#include "buffer.h"
#include <stdio.h>

/*
* PRODUCENT
*
*/

int main(int argc, char* argv[]){
buf_initialise(atoi(argv[1]),atoi(argv[2]));

srand(time(NULL));
queue_clear();
while(1){
buf_push(1000*(rand()%100));
}

return 0;
}
