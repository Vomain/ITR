#include "Producer.h"

Producer::Producer(int schedPolicy, int nLoops, double *pCounter, Mutex *mutex) :
        CounterThread(schedPolicy, nLoops, pCounter), mutex(mutex) {

}

void Producer::run() {

}
