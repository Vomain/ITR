#ifndef ITR_TIMESPEC_H
#define ITR_TIMESPEC_H

#include <time.h>
#include <math.h>

class Timespec : public timespec { // Hérite de timespec
public:
    Timespec();

    Timespec from_ms(double);

    double to_ms();
};

Timespec operator+(Timespec, Timespec);

#endif //ITR_TIMESPEC_H
