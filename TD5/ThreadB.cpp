#include "ThreadB.h"
#include "Lock.h"

ThreadB::ThreadB(Semaphore *semaphore): Thread(SCHED_RR), semaphore(semaphore)
{}

void ThreadB::run() {
    sleep(10);
}