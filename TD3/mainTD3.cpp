#include "Chrono.h"
#include "Sleeper.h"
#include <stdio.h>
int main(int argc, char *argv[]){
    /*
     * Test du chrono
     */
    Sleeper sleeper(3000);
    Chrono chrono1 = Chrono(); // On lance le chrono

    sleeper.start(7);
    sleeper.join(); // On attend

    printf("StartTime %f\n", chrono1.startTime());
    printf("StopTime %f\n", chrono1.stopTime());
    printf(chrono1.isActive() ? "chrono actif\n" : "chrono inactif\n"); // Le chrono doit encore etre actif
    printf("Temps intermédiaire %f\n", chrono1.lap()); // On sort le temps intermédiaire

    sleeper.start(7);
    sleeper.join(); // 2e tour

    chrono1.stop(); //arrêt chrono

    printf("StartTime %f\n", chrono1.startTime());
    printf("StopTime %f\n", chrono1.stopTime());
    printf(chrono1.isActive() ? "chrono actif\n" : "chrono inactif\n"); // Il doit donc être inactif
    printf("Temps final %f\n", chrono1.lap()); // Lecture chrono

}