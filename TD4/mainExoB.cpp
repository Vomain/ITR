#include "ProtectedCounterThread.h"

int main(int argc, char *argv[]) {
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Mutex mutex(true);
    ProtectedCounterThread counterThreadA(schedPolicy, 60000, &counter, &mutex);
    ProtectedCounterThread counterThreadB(schedPolicy, 30000, &counter, &mutex);

    printf("countThreads created!\n");

    counterThreadA.start(8);
    counterThreadB.start(8);

    printf("countThreads started!\n");

    counterThreadA.join();
    counterThreadB.join();

    printf("countThreads done!\n");

    printf("compteur : %0.f\n", counter);

    return 0;
}
