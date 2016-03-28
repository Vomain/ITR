#ifndef ITR_PRODUCER_H
#define ITR_PRODUCER_H

#include "Thread.h"
#include "Fifo.h"
#include "Condition.h"

class Producer : public CounterThread {
public:
    Producer(int schedPolicy, int nLoops, Fifo<int> *fifo);

    void run();

private:
    Fifo<int> *fifo;
};

#endif //ITR_PRODUCER_H
