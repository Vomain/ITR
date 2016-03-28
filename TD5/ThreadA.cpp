#include "ThreadA.h"
#include "Lock.h"

ThreadA::ThreadA(Semaphore *semaphore): Thread(SCHED_RR), semaphore(semaphore)
{}

void ThreadA::run() {
    sleep(10);
    *semaphore.take();
    sleep(10);
    *semaphore.give();
    sleep(20);
}