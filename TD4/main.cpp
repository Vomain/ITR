#include "CounterThread.h"
#include <stdio.h>
#include <errno.h>
	
int main(int argc, char* argv[])
{
	int schedPolicy = SCHED_RR;
	double counter = 0.0;

	CounterThread counterThreadA(schedPolicy, 150000, &counter);
	
	printf("countThread created!\n");
	counterThreadA.start(8);
	printf("countThread started!\n");
	

	if(counterThreadA.join(1000000)==110)
	{
		printf("Time out !\n");
	}
	
	printf("countThread done!\n");
	
	printf("compteur : %0.f\n", counter);
	
	return 0;
}
