#include "queue.h"


#include <iostream>
#include <cstdlib>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/shm.h>



/**
 * queue initialisation - takes shared memory key and queue size
 */
Queue::Queue(int shm_key, int q_size){
	size = q_size; 
	count = 0;
	int queue_segment_size = (size+2)*sizeof(int);
	if((id = shmget(shm_key, queue_segment_size, 0666|IPC_CREAT))==-1){
		return;
		//printf("Blad tworzenia kolejki (shmget) %d!\n", id); //TODO throw
	}
	queue = (int*)shmat(id, NULL, 0); //TODO blad?
	if(queue[0]==0)queue[0]=size+1; // only if it's a fresh start
	if(queue[1]==0)queue[1]=size+1;
#ifdef TEST_QUE
	std::cout<<"Queue initialised"<<std::endl;
#endif
}

/**
 * destructor
 */
Queue::~Queue(){
	shmdt(queue);
#ifdef TEST_QUE
	std::cout<<"Queue destroyed"<<std::endl;
#endif
}


/**
 * push
 */
int Queue::push(int data){
	usleep(500000);
	++count;
	queue[queue[0]] = data; // insert element 
	decrement(&queue[0]); // move the pointer 
#ifdef TEST_QUE
	std::cout<<"Queue pushed" <<std::endl;
#endif
	return 1;
}

/**
  pop front
  */
int Queue::popFront(){
	usleep(1000000);
	--count;
	int temp_index;
	if(queue[0]==size+1) { // the first empty element is the last in the queue
		temp_index = 2;
	}
	else{
		temp_index = queue[0]+1;
	}
	int retval = queue[temp_index]; // take the element 
	queue[temp_index] = 0; // clear (for legibility) 
	increment(&queue[0]); // move the pointer 
#ifdef TEST_QUE
	std::cout<<"Queue popped front"<<std::endl;
#endif
	return retval;
}

/**
 * pop back
 */
int Queue::popBack(){
	usleep(1000000);
	--count;
	int retval = queue[queue[1]]; // take the element 
	queue[queue[1]] = 0; // clear (for legibility's sake) 
	decrement(&queue[1]); // move the pointer 
#ifdef TEST_QUE
	std::cout<<"Queue popped back" <<std::endl;
#endif
	return retval;
}

/**
 * helper function for incrementing the pointers to the end and beginning
 * of the queue
 */
void Queue::increment(int* element){
	if(*element == size+1){
		*element = 2;
	}
	else{
		*element+=1;
	}
#ifdef TEST_QUE
	std::cout<<"Queue incremented" <<std::endl;
#endif
}

/**
 * the same as above, but for decrementing
 */
void Queue::decrement(int* element){
	if(*element == 2){
		*element = size+1;
	}
	else{
		*element-=1;
	}
#ifdef TEST_QUE
	std::cout<<"Queue decremented" <<std::endl;
#endif
}

/**
 * helper function for clearing the list
 */
void Queue::clear(){
	int i;
	queue[0] = size +1;
	queue[1] = size +1;
	count = 0;
	for(i = 2; i<=size+1; i++){
		queue[i] = 0;
	}
#ifdef TEST_QUE
	std::cout<<"Queue cleared" <<std::endl;
#endif
}

/**
 * helper function for showing the queue 
 */
int Queue::list(){
	system("clear");
	int i;
	std::cout<<"count: "<<count<<std::endl;
	std::cout<<"queue[0]="<<queue[0]<<std::endl<<"queue[1]="<<queue[1]<<std::endl;
	for(i = 2; i<=size+1; i++){
		std::cout<<"|\t-\t|\n|\t"<<queue[i]<<"\t|\n"<<std::endl;
	}
	return 1;
#ifdef TEST_QUE
	std::cout<<"Queue listed" <<std::endl;
#endif
}

int Queue::get_size(){
return size;
}

int Queue::get_count(){
return count;
}

#ifdef TEST_QUE
int main(int argc, char* argv[]){
	std::cout<<"Beginning of TEST_QUE"<<std::endl;
	Queue * que;
	que = new Queue(6750, 4);
	que->push(20);
	que->push(30);
	que->push(40);
	que->list();
	que->popFront();
	que->popBack();
	que->list();
	que->clear();
	usleep(500000);
	que->list();
	delete(que);
	std::cout<<"End of TEST_QUE"<<std::endl;
}
#endif
