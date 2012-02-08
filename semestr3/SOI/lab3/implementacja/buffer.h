#ifndef BUFFER_H
#define BUFFER_H
/* functions */
int buf_initialise(int, int queue_size);
int buf_push(int data);
int buf_pop_front();
int buf_pop_back();
#endif
