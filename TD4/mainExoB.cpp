#include "CounterThread.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int schedPolicy = SCHED_RR;
	double counter = 0.0;
    size_t stackSize = 100000000;  // Doit être supérieur à PTHREAD_STACK_MIN (16384) bytes

	CounterThread counterThread(schedPolicy, 15000, &counter);
	printf("countThread created!\n");

    counterThread.setStackSize(stackSize);
    printf("countThread sized!\n");

    counterThread.start(8);
    printf("countThread started!\n");

//    printf("countThread fell asleep!\n");
//    counterThread.sleep(0);
//    printf("countThread woke up!\n");
    
//	if(counterThread.join(100000000)==110)
//	{
//		printf("Time out !\n");
//	}

    counterThread.join();
	
	printf("countThread done!\n");
	
	printf("compteur : %0.f\n", counter);
	
	return 0;
}
