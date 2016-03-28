#include "Waiter.h"
#include "Lock.h"

Waiter::Waiter(Semaphore *semaphore): Thread(SCHED_RR), semaphore(semaphore)
{}

void Waiter::run() {
    sleep(30);
}