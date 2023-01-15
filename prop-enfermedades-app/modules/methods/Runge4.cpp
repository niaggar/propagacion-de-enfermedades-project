#include "Runge4.h"
#include "methods.h"

Runge4::Runge4(double b, double k, function<double(double, double, double, double, double, double)> f1, function<double(double, double, double, double, double, double)> f2, function<double(double, double, double, double, double, double)> f3)
{
    this->b = b;
    this->k = k;

    this->f1 = f1;
    this->f2 = f2;
    this->f3 = f3;
}

double *Runge4::Calc(double t, double dt, double s, double i, double r)
{
    double *result = new double[3];

    k11 = f1(t, s, i, r, b, k);
    k21 = f2(t, s, i, r, b, k);
    k31 = f3(t, s, i, r, b, k);

    double tdt2 = t + dt / 2.0;

    k12 = f1(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0, b, k);
    k22 = f2(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0, b, k);
    k32 = f3(tdt2, s + k11 * dt / 2.0, i + k21 * dt / 2.0, r + k31 * dt / 2.0, b, k);

    k13 = f1(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0, b, k);
    k23 = f2(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0, b, k);
    k33 = f3(tdt2, s + k21 * dt / 2.0, i + k22 * dt / 2.0, r + k32 * dt / 2.0, b, k);

    double tdt = t + dt;

    k14 = f1(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt, b, k);
    k24 = f2(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt, b, k);
    k34 = f3(tdt, s + k13 * dt, i + k23 * dt, r + k33 * dt, b, k);

    double f1_t = s + (k11 + 2.0 * k12 + 2.0 * k13 + k14) * dt / 6.0;
    double f2_t = i + (k21 + 2.0 * k22 + 2.0 * k23 + k24) * dt / 6.0;
    double f3_t = r + (k31 + 2.0 * k32 + 2.0 * k33 + k34) * dt / 6.0;

    result[0] = f1_t;
    result[1] = f2_t;
    result[2] = f3_t;

    return result;
}
