#include "Fifo.h"
#include "Timespec.h"

template <typename T>
void Fifo<T>::push(T element) {
    /**
    * Cette fonction ajoute un élément en tête de la liste
    * Les tâches en attentes sont notifiées
    */
    elements.push(element);
    condition.notify();
}

template <typename T>
T Fifo<T>::pop() {
    /**
    * Cette fonction enlève l'élément en tête de la liste
    * Si l'élément n'est pas disponible, l'appel est bloquant
    */
    Lock lock(condition);
    while(elements.empty()){
        condition->wait();
    }
    T element = elements.front();
    elements.pop();
    return element;
}

template <typename T>
T Fifo<T>::pop(double timeout_ms) {
    /**
    * Cette fonction enlève l'élément en tête de la liste
    * Si l'élément n'est pas disponible, l'appel est bloquant
    * Si le timeout est dépassé, la fonction renvoie une exception
    */
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
            bool result = condition->wait(timeout);
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
