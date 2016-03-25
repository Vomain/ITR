#ifndef SEMAPHORE_H_INCLUDED
#define SEMAPHORE_H_INCLUDED

#include "Condition.h"

class Semaphore
{
public:
    Semaphore(unsigned, unsigned);
	void give();
	void flush();
	void take();
	bool take(double);
private:
	unsigned counter;
	unsigned maxCount;
    Condition condition;
};

#endif
