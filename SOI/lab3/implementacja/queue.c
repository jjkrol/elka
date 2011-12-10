#include "queue.h"

#include <stdio.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/shm.h>


int queue_id;
int queue_size;

/*
*
* queue initialisation - takes shared memory key and queue size
*
*/
int* queue_init(int shm_key, int q_size){
queue_size = q_size; 
int queue_segment_size = (queue_size+2)*sizeof(int);
if((queue_id = shmget(shm_key, queue_segment_size, 0666|IPC_CREAT))==-1){
	printf("Blad tworzenia kolejki (shmget) %d!\n", queue_id);
	return queue_id;
}
if((queue = shmat(queue_id, NULL, 0))==-1){
	printf("Blad tworzenia kolejki (shmat) %d!\n", queue);
	}	
if(queue[0]==0)queue[0]=queue_size+1; // only if it's a fresh start
if(queue[1]==0)queue[1]=queue_size+1;
return queue;
}

/*
*
* push
*
*/
int queue_push(int data){
usleep(500000);
	queue[queue[0]] = data; // insert element 
	queue_decrement(&queue[0]); // move the pointer 
	return 1;
}

/*
*
* pop front
*
*/
int queue_pop_front(){
usleep(1000000);
	int temp_index;
	if(queue[0]==queue_size+1) { // the first empty element is the last in the queue
		temp_index = 2;
	}
	else{
		temp_index = queue[0]+1;
	}
	int retval = queue[temp_index]; // take the element 
	queue[temp_index] = 0; // clear (for legibility) 
	queue_increment(&queue[0]); // move the pointer 
	return retval;
}

/*
*
* pop back
*
*/
int queue_pop_back(){
usleep(1000000);
	int retval = queue[queue[1]]; // take the element 
	queue[queue[1]] = 0; // clear (for legibility's sake) 
	queue_decrement(&queue[1]); // move the pointer 
	return retval;
}

/*
*
* helper function for incrementing the pointers to the end and beginning
* of the queue
*/
void queue_increment(int* element){
	if(*element == queue_size+1){
		*element = 2;
	}
	else{
		*element+=1;
	}
}

/*
*
* the same as above, but for decrementing
*
*/
void queue_decrement(int* element){
	if(*element == 2){
		*element = queue_size+1;
	}
	else{
		*element-=1;
	}
}
int queue_deact(){
shmdt(queue);
}

/*
*
* helper function for clearing the list
*
*/
void queue_clear(){
	int i;
	queue[0] = queue_size +1;
	queue[1] = queue_size +1;
	for(i = 2; i<=queue_size+1; i++){
		queue[i] = 0;
	}
}

/*
* 
* helper function for showing the queue 
*
*/
int queue_list(){
	system("clear");
	int i;
	printf("queue[0]=%d\nqueue[1]=%d\n", queue[0], queue[1]);
	for(i = 2; i<=queue_size+1; i++){
		printf("|\t-\t|\n|\t%d\t|\n", queue[i]);
	}
return 1;
}
