#include "Fifo.h"
#include "Consumer.h"
#include "Producer.h"

int main(int argc, char *argv[]) {


    int schedPolicy = SCHED_RR;

    Fifo<int> fifo;  // stack of ints

    Producer producer(schedPolicy, 30, &fifo);
    Consumer consumer1(schedPolicy, 10, &fifo);
    Consumer consumer2(schedPolicy, 10, &fifo);
    Consumer consumer3(schedPolicy, 10, &fifo);
    
    producer.start(8);
    consumer1.start(8);
    consumer2.start(8);
    consumer3.start(8);
    
    producer.join(8);
    consumer1.join(8);
    consumer2.join(8);
    consumer3.join(8);
    
    printf("Terminé !");
    printf("Compteurs : \n   1 : %d, \n   2 : %d, \n   3 : %d", consumer1.compteur, consumer2.compteur, consumer3.compteur);
        
    return 0;
}


