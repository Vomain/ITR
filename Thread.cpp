#include "Thread.h"
#include <pthread.h>

void Thread::Thread(int schedPolicyArg){
	schedPolicy = schedPolicyArg;
}
	
void Thread::start(int priority)
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, schedPolicy);
	sched_param schedParams;
	schedParams.sched_priority = priority;
	pthread_attr_setschedparam(&attr, &schedParams);	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	
	pthread_create(&tid, &attr, call_run, NULL);
}

void Thread::join(){
	
}

void* call_run(void *arg_pointer)
{
	run();
}
