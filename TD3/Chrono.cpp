#include "Chrono.h"
#include <stdio.h>

Chrono::Chrono() {
    printf("chrono created\n");
    clock_gettime(CLOCK_REALTIME, &stopTime_);
    clock_gettime(CLOCK_REALTIME, &startTime_);
}

void Chrono::stop(){
    clock_gettime(CLOCK_REALTIME, &stopTime_);
}
void Chrono::restart(){
    clock_gettime(CLOCK_REALTIME, &startTime_);
}
double Chrono::lap(){
    Timespec t_lap;
    clock_gettime(CLOCK_REALTIME, &t_lap);
    return (t_lap - startTime_).to_ms();
}

bool Chrono::isActive(){
    return &startTime_ < &stopTime_;
}

