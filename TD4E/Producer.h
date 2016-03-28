#ifndef ITR_PRODUCER_H
#define ITR_PRODUCER_H

#include "CounterThread.h"
#include "Lock.h"

class Producer : public CounterThread {
public:
    Producer(int schedPolicy, int nLoops, double *pCounter, Mutex *mutex);

    void run();

private:

    Mutex *mutex;
};



#endif //ITR_PRODUCER_H
