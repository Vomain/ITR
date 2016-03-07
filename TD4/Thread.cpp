#include "Thread.h"
#include <stdio.h>

Thread::Thread(int schedPolicy) : schedPolicy(schedPolicy)
{}
	
void Thread::start(int priority)
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, schedPolicy);
	sched_param schedParams;
	schedParams.sched_priority = priority;
	pthread_attr_setschedparam(&attr, &schedParams);	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	
	pthread_create(&tid, &attr, call_run, this);
}

void Thread::join(){
	pthread_join(tid, NULL);
}

void* Thread::call_run(void *arg_pointer)
{
	((Thread *) arg_pointer)->run();
}

void Thread::run()
{}
