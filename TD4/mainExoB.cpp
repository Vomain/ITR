#include "ProtectedCounterThread.h"
#include <stdio.h>
#include "Mutex.h"

int main(int argc, char* argv[])
{
	int schedPolicy = SCHED_RR;
	double counter = 0.0;

	Mutex mutex(true);
	ProtectedCounterThread counterThreadA(schedPolicy, 150000, &counter, &mutex);
	ProtectedCounterThread counterThreadB(schedPolicy, 150000, &counter, &mutex);
	
	printf("countThreads created!\n");

    counterThreadA.start(8);
    counterThreadB.start(8);
    
    printf("countThreads started!\n");

    counterThreadA.join();
    counterThreadB.join();
	
	printf("countThreads done!\n");
	
	printf("compteur : %0.f\n", counter);
	
	return 0;
}
