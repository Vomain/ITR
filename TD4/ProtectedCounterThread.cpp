#include "ProtectedCounterThread.h"
#include <stdio.h>
#include "Lock.h"

ProtectedCounterThread::ProtectedCounterThread(int schedPolicy, int nLoops, double *pCounter, Mutex *mutex)
: CounterThread(schedPolicy, nLoops, pCounter)
{}
	
void ProtectedCounterThread::run(){
	for (int i = 0; i < nLoops ; i++) 
	{
		//try{
			{
				Lock lock(mutex);
				*pCounter += 1.0;
			}
		//} 
		/*catch (std::exception& e) 
		{
			printf("wowowow");
		}*/
	}
}
