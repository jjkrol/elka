#pragma once

#include "semaphore.h"
#include "condition.h"

class Monitor{
	Semaphore * sem;

public:
	Monitor(key_t);
	~Monitor();
	void enter();
	void leave();
	void wait(Condition &);
	void signal(Condition &);

};
