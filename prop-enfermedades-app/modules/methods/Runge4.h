#ifndef RUNGE4_H
#define RUNGE4_H

#include "models/Model.h"

using namespace std;

class Runge4
{
private:
    double k11, k12, k13, k14;
    double k21, k22, k23, k24;
    double k31, k32, k33, k34;
    double b, k;
    Model *model;

public:
    Runge4();
    void SetModel(Model *);
    double *Calc(double, double, double, double, double);
};

#endif
