#ifndef COUNTER_THREAD_H
#define COUNTER_THREAD_H

#include "Thread.h"



class CounterThread: public Thread
{
public:
	CounterThread(int schedPolicy, int nLoops, double *pCounter);
protected:
	void run();
private:
	int nLoops;
	double *pCounter;
};

#endif
