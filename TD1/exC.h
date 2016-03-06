#ifndef ITR_EXC_H
#define ITR_EXC_H

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <string.h>

void incr(unsigned int, double*);
void printTime(timespec*, timespec*);
void *call_incr(void *arg_pointer);

struct arg_struct
{
    unsigned int nLoops;
    double *pCounter;
    pthread_mutex_t mutex;
    bool useMutex;
};

#endif //ITR_EXC_H
