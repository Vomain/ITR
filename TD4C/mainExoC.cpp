#include "ProtectedCounterThread.h"
#include "Condition.h"

int main(int argc, char *argv[]) {
    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    Mutex mutex(true);
    
    
    ProtectedCounterThread counterThreadA(schedPolicy, 10, &counter, &mutex);
    printf("countThread created!\n");

    counterThreadA.start(8);
    counterThreadA.start(8);

    printf("countThreads started!\n");

    counterThreadA.join();

    printf("countThreads done!\n");

    printf("compteur : %0.f\n", counter);

    return 0;
}
