#include "Sleeper.h"

Waiter::Waiter(int seconds_to_wait): Thread(SCHED_RR), seconds_to_wait(seconds_to_wait)
{}

void Waiter::run() {
    sleep(seconds_to_wait);
}