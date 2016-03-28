#ifndef ITR_CONSUMER_H
#define ITR_CONSUMER_H

#include "Thread.h"
#include "Fifo.h"
#include "Condition.h"

class Consumer : public Thread {
public:
    Consumer(int schedPolicy, int nLoops, Fifo<int> *fifo);

    void run();

    int compteur;
    
private:
    Fifo<int> *fifo;
};


#endif //ITR_CONSUMER_H
