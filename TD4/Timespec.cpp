#include "Timespec.h"

Timespec::Timespec()
{}

Timespec operator+(Timespec ts1, Timespec ts2)
{
    ts1.tv_sec += ts2.tv_sec + (ts1.tv_nsec + ts2.tv_nsec) / 1000000000; // Renormalisation des secondes
    ts1.tv_nsec += ts2.tv_nsec;
    ts1.tv_nsec %= 1000000000; // Renormalisation des nanosecondes
    return ts1;
}

Timespec Timespec::from_ms(double t_ms)
{
    this->tv_nsec = (__syscall_slong_t) (fmod(t_ms, 1000) * 1000000);
    this->tv_sec = (__time_t) (t_ms / 1000);
}

double Timespec::to_ms()
{
    double result = 0;
    result += this->tv_nsec / 1000000 + this->tv_sec * 1000;

    return result;
}
