#include "CounterThread.h"
#include <stdio.h>
	
int main(int argc, char* argv[])
{
	int schedPolicy = SCHED_RR;
	double counter = 0.0;
	
	CounterThread counterThread(schedPolicy, 15, &counter);
	printf("countThread created!\n");
	
	counterThread.start(8);
	printf("countThread started!\n");
	
	counterThread.join();
	printf("countThread done!\n");
	
	printf("%0.f", counter);
	
	return 0;
}
