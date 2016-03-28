#ifndef ITR_CONSUMER_H
#define ITR_CONSUMER_H

#include "CounterThread.h"
#include "Fifo.h"

class Consumer : public CounterThread {
public:
    Consumer(int schedPolicy, int nLoops, Mutex *mutex, Fifo<int> *fifo);

    void run();

private:
    Mutex *mutex;
    Fifo<int> *fifo;
};


#endif //ITR_CONSUMER_H
