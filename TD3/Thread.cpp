#include "Thread.h"
#include <stdio.h>

Thread::Thread(int schedPolicy) : schedPolicy(schedPolicy) {
    pthread_attr_init(&attr);
}

void Thread::start(int priority) {
    pthread_attr_setschedpolicy(&attr, schedPolicy);
    sched_param schedParams;
    schedParams.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &schedParams);
    //pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    //printf("launching pthread create\n");
    pthread_create(&tid, &attr, call_run, this);
    //printf("pthread created \n");
}

void Thread::join() {
    pthread_join(tid, NULL);
}

int Thread::join(double timeout_ms) {

    Timespec t;
    t.from_ms(timeout_ms);

    return pthread_timedjoin_np(tid, NULL, &t);
}

void *Thread::call_run(void *arg_pointer) {
    // printf("CALL RUN LAUNCHED\n");
    ((Thread *) arg_pointer)->run();
}

void Thread::run() { 
    printf("RUN sans rien\n");
}

void Thread::sleep(double delay_ms) {

    Timespec t;
    t.from_ms(delay_ms);

    nanosleep(&t, NULL);
}

void Thread::setStackSize(size_t stackSize) {
    printf("SET STACK SIZE LAUNCHED\n");
    pthread_attr_setstacksize(&attr, stackSize);
}

