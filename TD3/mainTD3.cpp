#include "Chrono.h"
#include "Sleeper.h"
#include <stdio.h>
int main(int argc, char *argv[]){
    Sleeper sleeper(3000);
    Chrono chrono1 = Chrono();

    sleeper.start(7);
    sleeper.join();

    printf(chrono1.isActive() ? "chrono actif\n" : "chrono inactif\n");
    printf("Temps intermédiaire %f\n", chrono1.lap());

    sleeper.start(7);
    sleeper.join();

    chrono1.stop();

    printf(chrono1.isActive() ? "chrono actif\n" : "chrono inactif\n");
    printf("Temps final %f\n", chrono1.lap());

}