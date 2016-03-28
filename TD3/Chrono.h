#ifndef ITR_CHRONO_H
#define ITR_CHRONO_H

#include <time.h>
#include <math.h>
#include "Timespec.h"

class Chrono {
public:
    Chrono();
    void stop();
    void restart();
    bool isActive();
    double startTime();
    double stopTime();
    double lap();
    double to_ms();

protected:
    double startTime_;
    Timespec stopTime_;
};


#endif //ITR_CHRONO_H
