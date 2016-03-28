#include "Chrono.h"
#include "Sleeper.h"
#include <stdio.h>
int main(int argc, char *argv[]){
    Chrono chrono1 = Chrono();
    Sleeper sleeper(3000);

    sleeper.start(7);
    sleeper.join();
    printf(chrono1.isActive() ? "true" : "false");
    printf("lolfd %f\n", chrono1.lap());
    sleeper.start(7);
    sleeper.join();

    chrono1.stop();
    printf(chrono1.isActive() ? "true" : "false");
    Timespec temps;
    printf("lolfd %f\n", chrono1.lap());

}