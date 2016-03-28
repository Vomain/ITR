#include "Sleeper.h"

Sleeper::Sleeper(int seconds_to_wait): Thread(SCHED_RR), seconds_to_wait(seconds_to_wait)
{}

void Sleeper::run() {
    sleep(seconds_to_wait);
}