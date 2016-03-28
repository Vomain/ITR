#include "ProtectedCounterThread.h"
#include "Fifo.h"
#include "Consumer.h"

int main(int argc, char *argv[]) {
    /**
    * C'est ici que nous lançons notre main
    */

    int schedPolicy = SCHED_RR;
    double counter = 0.0;

    printf("C'est bon, j'ai réussi à compiler !\n");

    Fifo<int> fifo;  // stack of ints

    int n = 10;

    for (int i = 0; i < n; i++)
    {
        printf("Je push !\n");
        fifo.push(666);
    }

    Consumer consumer(schedPolicy, 15, &counter, &fifo);

    printf("J'ai créé consumer \n");

    for (int i = 0; i < 100; i++) {
        consumer.bite();
        char * result = (char *) consumer.bite();
        printf("ICI C'EST LA BOUCLE\n");
        printf("%s\n",  result);

    }

//    ProtectedCounterThread counterThreadA(schedPolicy, 10, &counter, &mutex);
//    Mutex mutex(true);
//
//    printf("countThread created!\n");
//
//    counterThreadA.start(8);
//    counterThreadA.start(8);
//
//    printf("ncountThreads started!\n");
//
//    counterThreadA.join();
//    counterThreadA.join();
//
//    printf("countThreads done!\n");
//
//    printf("compteur : %0.f\n", counter);
    return 0;
}


