#include "Chrono.h"
#include <stdio.h>

Chrono::Chrono() {
    printf("gfgggf");
    clock_gettime(CLOCK_REALTIME, &stopTime_);
    clock_gettime(CLOCK_REALTIME, &startTime_);
}

void Chrono::stop(){
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void Chrono::restart(){
    clock_gettime(CLOCK_REALTIME, &startTime_);
}
double lap(){

}

void Chrono::isActive(){
    return &startTime_ < &stopTime_;
}

