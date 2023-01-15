
#include "methods.h"

double Suceptibles(double t, double s, double i, double r, double b, double k)
{
    return -b * s * i;
}

double Infectados(double t, double s, double i, double r, double b, double k)
{
    return b * s * i - k * i;
}

double Recuperados(double t, double s, double i, double r, double b, double k)
{
    return k * i;
}
