#ifndef ITR_CONSUMER_H
#define ITR_CONSUMER_H

#include "CounterThread.h"
#include "Fifo.h"

class Consumer : public CounterThread {
public:
    Consumer(int schedPolicy, int nLoops, double *pCounter,  Fifo<int> *fifo);

    char bite();

private:

    Fifo<int> *fifo;
};


#endif //ITR_CONSUMER_H
