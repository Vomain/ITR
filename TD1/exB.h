#ifndef ITR_EXB_H
#define ITR_EXB_H

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

void incr(unsigned int, double*);
void printTime(timespec*, timespec*);
void *call_incr(void *arg_pointer);
void incr(unsigned int nLoops, double* pCounter);

struct arg_struct
{
    unsigned int nLoops;
    double *pCounter;
};

#endif //ITR_EXB_H
