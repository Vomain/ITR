#ifndef ITR_FIFO_H
#define ITR_FIFO_H

#include <queue>
#include "Condition.h"

class Fifo {
public:
    Fifo(std::queue<int> elements);

    int push();
    void pop();
    bool pop(double);

private:
    std::queue<int> elements;
    Condition condition;

};


#endif //ITR_FIFO_H
