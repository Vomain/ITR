#include "CounterThread.h"


void CounterThread::CounterThread(int schedPolicy, int nLoops, double *pCounter)
: Thread(schedPolicy), nLoops(nLoops), pCounter(pCounter)
{}
	
static void CounterThread::run(){
	for (int i = 0; i < nLoops ; i++) 
	{
		*pCounter += 1.0;
	}
}
