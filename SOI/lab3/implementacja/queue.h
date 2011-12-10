#ifndef QUEUE_H
#define QUEUE_H
int *queue;

int* queue_init(int, int);
int queue_push(int);
int queue_pop_front();
int queue_pop_back();
int queue_list();
void queue_increment(int*);
void queue_decrement(int*);
void queue_clear();

#endif
