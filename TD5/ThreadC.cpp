#include "ThreadC.h"
#include "Lock.h"

ThreadC::ThreadC(Semaphore *semaphore): Thread(SCHED_RR), semaphore(semaphore)
{}

void ThreadC::run() {
    sleep(20);
    *semaphore.take();
    sleep(20);
    *semaphore.give();
    sleep(10);
}