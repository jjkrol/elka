#pragma once

#include "semaphore.h"
#include <sys/types.h>

class Condition{
	friend class Monitor;
	public:
	Condition(key_t key);
	~Condition();
#ifndef TEST_CON
	private:
#endif
	void wait();
	bool signal();

	private:
	Semaphore * sem;
	int waitingCount;

};
