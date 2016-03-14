#include "Semaphore.h"
#include <stdio.h>
#include "Timespec.h"

Semaphore::Semaphore(unsigned counter, unsigned maxCount) : counter(0), maxCount(UINT_MAX)
{}

void Semaphore::give() 
{
	if(counter != maxCount)
	{
		counter++;
	}
}

void Semaphore::flush() 
{
	// if block, free
	// notifyAll
}

void Semaphore::take() 
{
	
	if (counter == 0) 
	{
		//block	
	}
	counter--;
}

bool Semaphore::take(double timeout_ms) 
{
	
}

Semaphore::~Semaphore() {
    // destroy
}

//clock_gettime(CLOCK_THREAD_CPUTIME_IDn &my_timespec);
//clock_gettime(CLOCK_REALTIME, &my_timespec);
