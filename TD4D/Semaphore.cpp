#include "Semaphore.h"
#include "Lock.h"
#include <stdio.h>

unsigned UINT_MAX = 1000;

Semaphore::Semaphore(unsigned counter=0, unsigned maxCount=UINT_MAX) : counter(counter), maxCount(maxCount)
{}


/*
    Rend un jeton au sémaphore, si on atteint pas le maximum.
    Quand le compteur est incrémenté, un des threads en attente sont notifiés
*/

void Semaphore::give() 
{
    Lock(&condition); //Protège la variable counter
	if(counter < maxCount)
	{
		counter++;
        condition.notify();
	}
}

/*
    Notifie tous les thread en attente de la condition
*/

void Semaphore::flush() 
{
	condition.notifyAll();
}

/*
    Prend un jeton au sémaphore
    S'il n'y a plus de jeton, l'appel est bloquant et le thread est mis en pause par la condition. A l'arrivée d'un signal ou d'un broadcast, la condition est testée à nouveau. 
*/

void Semaphore::take() 
{
	Lock(&condition);
	if (counter == 0) 
	{
		while(counter==0){
            condition.wait();
        }
	} else {
        counter--;
    }
}

/*
    Idem, avec un timeout sur le temps de lock
    //TODO à revoir
*/

bool Semaphore::take(double timeout_ms) 
{
    Timespec tmax; // On instancie notre classe Timespec
    clock_gettime(CLOCK_REALTIME, &tmax); 

    Timespec t_timeout;
    t_timeout.from_ms(timeout_ms);
    
    //t1 devient le temps maximal à ne pas dépasser
    tmax = tmax + t_timeout;
    
	Lock(&condition);
	if (counter == 0) 
	{
		while(counter==0){
            Timespec tmaxWait;
            clock_gettime(CLOCK_REALTIME, &tmaxWait);
            tmaxWait = tmax - tmaxWait;
            
            double timeout = tmaxWait.to_ms();
            bool result = condition.wait(timeout);
            if(!result){ // si c'est un timeout qui a libéré le thread
                return false;
            }
        }
        
	}
    counter--;
    return true;
}