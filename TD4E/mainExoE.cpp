#include "Fifo.h"
#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[]) {

    int schedPolicy = SCHED_RR;

    Fifo<int> fifo;  // stack of ints

    Producer producer1(schedPolicy, 2000, &fifo);
    Producer producer2(schedPolicy, 2000, &fifo);
    Consumer consumer1(schedPolicy, 1000, &fifo);
    Consumer consumer2(schedPolicy, 1000, &fifo);
    Consumer consumer3(schedPolicy, 1000, &fifo);

    producer1.start(8);
    producer2.start(8);
    consumer1.start(8);
    consumer2.start(8);
    consumer3.start(8);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();
    
    printf("Terminé !");
    printf("Compteurs : \n   1 : %d, \n   2 : %d, \n   3 : %d\n", consumer1.compteur, consumer2.compteur, consumer3.compteur);
        
    return 0;
}


