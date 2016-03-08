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
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

    pthread_create(&tid, &attr, call_run, this);
}

void Thread::join() {
    pthread_join(tid, NULL);
}

int Thread::join(double timeout_ms) {
    struct timespec ts;
    time_t sec = (int) (timeout_ms / 1000);
    timeout_ms -= sec * 1000;
    ts.tv_sec = sec;
    ts.tv_nsec = timeout_ms * 1000000L;

    return pthread_timedjoin_np(tid, NULL, &ts);
}

void *Thread::call_run(void *arg_pointer) {
    ((Thread *) arg_pointer)->run();
}

void Thread::run() { }

void Thread::sleep(double delay_ms) {
    struct timespec ts;

    time_t sec = (int) (delay_ms / 1000);
    delay_ms -= sec * 1000;
    ts.tv_sec = sec;
    ts.tv_nsec = delay_ms * 1000000L;

    nanosleep(&ts, NULL);
}

void Thread::setStackSize(size_t stackSize) {
    pthread_attr_setstacksize(&attr, stackSize);
}

