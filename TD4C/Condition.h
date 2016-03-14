#ifndef CONDITION_H_INCLUDED
#define CONDITION_H_INCLUDED

#include "Mutex.h"

class Condition: public Mutex
{
public:
	Condition();
	Condition(bool);
	void wait();
	bool wait(double timeout_ms);
	void notify();
	void notifyAll();
private:
	pthread_cond_t cid;
};

#endif
