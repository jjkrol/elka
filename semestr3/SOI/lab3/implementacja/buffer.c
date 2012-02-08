/* our includes */
#include "buffer.h"
/* semaphores
*  must provide functions:
*   sem_alloc
*   sem_init
*   sem_proberen
*   sem_verhogen
*   sem_dealloc
*/
#include "semfunc.h"
/* queue
*  must provide functions:
*   queue_init
*   queue_push
*   queue_pop_front
*   queue_pop_back
*   queue_deact
*/
#include "queue.h" //queue

/* system includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

/* semaphore key definitions */
#define MUTEX 1000
#define FULL 1001
#define EMPTY 1002

/* semaphore id variables */
int sem_mutex;
int sem_full;
int sem_empty;

/* initialisation flag */
int initialised;

/*
* initialisation - takse shared memory key and queue_size
* returns 1 if everythings correct
*
*/
int buf_initialise(int shm_key, int queue_size){
/* allocate semaphores */
if((sem_mutex = sem_alloc(MUTEX, 0666 | IPC_CREAT))<0) return -1;
if((sem_full = sem_alloc(FULL, 0666 | IPC_CREAT))<0) return -1;  
if((sem_empty = sem_alloc(EMPTY, 0666 | IPC_CREAT))<0) return -1;
/* initialise semaphores */
int wynik;
if (sem_init(sem_mutex, 1)) return -1;
if (sem_init(sem_full, queue_size-1)) return -1;
if (sem_init(sem_empty, 0)) return -1;
printf("Tworze kolejke za pomoca klucz %d o dlugosci %di\n", shm_key, queue_size);
queue = queue_init(shm_key, queue_size);
initialised = 1;
printf("Initialised\n");
}

/*
*
* pop_front
* 
*/
int buf_pop_front(){
if (!initialised) { //sprawdz, czy zainicjalizowane
	printf("First initialise!\n");
	return -1;
}
sem_proberen(sem_empty);
sem_proberen(sem_mutex);
int retval = queue_pop_front();
sem_verhogen(sem_mutex);
sem_verhogen(sem_full);
return retval;
}

/*
*
* pop_back
* 
*/
int buf_pop_back(){
if (!initialised) { //sprawdz, czy zainicjalizowane
	printf("First initialise!\n");
	return -1;
}
sem_proberen(sem_empty);
sem_proberen(sem_mutex);
int retval = queue_pop_back();
sem_verhogen(sem_mutex);
sem_verhogen(sem_full);
return retval;
}

/*
*
* push
* 
*/
int buf_push(int data){
if(!initialised){ //sprawdz, czy zainicjalizowane
	printf("First initialise!\n");
	return -1;
}
sem_proberen(sem_full);
sem_proberen(sem_mutex);
int retval = queue_push(data);
sem_verhogen(sem_mutex);
sem_verhogen(sem_empty);
return retval;
}

/*
*
* deallocation of queue and semaphores
*
*/
int buf_deact(){
// queue
queue_deact();

//semaphores
sem_dealloc(sem_mutex);
sem_dealloc(sem_full);
sem_dealloc(sem_empty);
}


