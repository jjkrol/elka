#pragma once

#include "monitor.h"
#include "queue.h"

class Buffer{
	Monitor * mon;
	Queue * que;
	Condition notfull;
	Condition notempty;
	public:
Buffer(int, int);
~Buffer();
int push(int data);
int popFront();
int popBack();
void show();
void clear();
};
