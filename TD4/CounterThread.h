#ifndef COUNTER_THREAD_H
#define COUNTER_THREAD_H

#include "Thread.h"



class CounterThread public Thread
{
public:
	void CounterThread::CounterThread(int schedPolicy, int nLoops, double *pCounter)
protected:
	static void run();
private:
	int nLoops;
	double *pCounter;
};

#endif
