#include "Condition.h"
#include <stdio.h>

Condition::Condition(int schedPolicy, int nLoops, double *pCounter)
: Thread(schedPolicy), nLoops(nLoops), pCounter(pCounter)
{}
	
void CounterThread::run(){
	for (int i = 0; i < nLoops ; i++) 
	{
		*pCounter += 1.0;
	}
}
