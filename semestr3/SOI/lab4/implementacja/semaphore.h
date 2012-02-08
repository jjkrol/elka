#pragma once
/**
 * Semaphore class for providing semaphore objects
 */

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <iostream>

class Semaphore{
	int semid;
	public:
	Semaphore(key_t, int, int);
	~Semaphore();
	int proberen();
	int verhogen();
};

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminf *__buf;
};
