#include "Fifo.h"
#include "Timespec.h"

template <typename T>
void Fifo<T>::push(T element) {
    elements.push(element);
}

template <typename T>
T Fifo<T>::pop() {
    Lock lock(condition);
    while(elements.empty()){
        condition.wait();
    }
    T element = elements.front();
    elements.pop();
    return element;
}

template <typename T>
T Fifo<T>::pop(double timeout_ms) {
    Lock lock(condition);
    
    Timespec tmax; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &tmax);

    Timespec t_timeout;
    t_timeout.from_ms(timeout_ms);

    // tmax devient l'échéance à ne pas dépasser
    tmax = tmax + t_timeout;

    while(elements.empty()){
        Timespec tmaxWait;
        clock_gettime(CLOCK_REALTIME, &tmaxWait);
        
        if(tmax < tmaxWait){ // si échéance est avant le temps actuel
            throw EmptyException();
        } else {
            tmaxWait = tmax - tmaxWait; // délai encore disponible
            double timeout = tmaxWait.to_ms();
            bool result = condition.wait(timeout);
            if (!result) { // si c'est un timeout qui a libéré le thread
                throw EmptyException();
            }
        }
    }
    T element = elements.front();
    elements.pop();
    return element;
}

template class Fifo<int>;
