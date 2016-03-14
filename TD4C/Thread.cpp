#include "Thread.h"
#include <stdio.h>
#include "Lock.h" 

Thread::Thread(int schedPolicy) : schedPolicy(schedPolicy) {
    pthread_attr_init(&attr);
    condition = Condition(true);
    started = false;
}

bool Thread::start(int priority) {
	printf("Start !\n");
	
	{
		Lock lock(&condition);
		while(started)
		{
			printf(started ? "true" : "false");
			printf("Je vérifie si je suis pas déjà lancé\n");
			condition.wait();
			printf("Débloqué\n");
		}
		printf("Je suis pas lancé, j'y vais, c'est parti!\n");
		started = true;
	}
		
    pthread_attr_setschedpolicy(&attr, schedPolicy);
    sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &schedParams);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_create(&tid, &attr, call_run, this);
}


void Thread::join() {
    pthread_join(tid, NULL);
}

int Thread::join(double timeout_ms) {
    pthread_join(tid, NULL);
    Timespec t;
    t.from_ms(timeout_ms);

    return pthread_timedjoin_np(tid, NULL, &t);
}

void *Thread::call_run(void *arg_pointer) {
	Thread *t = (Thread *) arg_pointer;
	t->run();
	Lock lock(&(t->condition));
	t->started = false;
	(t->condition).notify();
}

void Thread::run() { }

void Thread::sleep(double delay_ms) {

    Timespec t;
    t.from_ms(delay_ms);

    nanosleep(&t, NULL);
}

void Thread::setStackSize(size_t stackSize) {
    pthread_attr_setstacksize(&attr, stackSize);
}

