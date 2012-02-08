#include "buffer.h"
#include <stdio.h>

int main(){
buf_initialise(9);

//queue_clear();
buf_push(8);
buf_pop_front();
buf_push(9);
buf_push(10);
buf_push(11);
buf_pop_back();
buf_pop_front();

buf_deact();
return 0;
}
