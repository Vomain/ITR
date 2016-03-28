#include "SemaphoreCounterThread.h"
#include "Mutex.h"
#include "ProtectedCounterThread.h"

int main(int argc, char *argv[]) {
    
    Mutex mutex(false);
    int schedPolicy = SCHED_RR;
    double counter = 0.0; // la ressource accessible par les trois tâches
    
    ProtectedCounterThread threadA(schedPolicy, 100, &counter, &mutex);
    ProtectedCounterThread threadB(schedPolicy, 100, &counter, &mutex);
    ProtectedCounterThread threadC(schedPolicy, 100, &counter, &mutex);
    
    Timespec t1, t2;
    clock_gettime(CLOCK_REALTIME, &t1);
    
    threadA.start(9);
    threadB.start(8);
    threadC.start(7);
    
    threadA.join();
    clock_gettime(CLOCK_REALTIME, &t2);   
    
    threadB.join();
    threadC.join();

    t2 = t2 - t1;
    printf("Le thread A est terminé en %f ms", t2.to_ms());
}
