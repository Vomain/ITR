#include "Chrono.h"
#include "Sleeper.h"
#include <stdio.h>
int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    Sleeper sleeper(3000);

    sleeper.start(7);
    sleeper.join();
    printf("lofggfgffd %b\n", chrono1.isActive());
    printf("lolfd %f\n", chrono1.lap());
    sleeper.start(7);
    sleeper.join();

    chrono1.stop();
    printf("lgfggfd %b\n", chrono1.isActive());
    Timespec temps;
    printf("lolfd %f\n", chrono1.lap());

}