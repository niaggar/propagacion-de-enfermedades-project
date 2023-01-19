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
    double **result;
    double length;
    double *Calc(double, double, double, double, double);
public:
    Runge4();
    void SetModel(Model *);
    void DoMethod(double, double, double, double, double, double);

    double **GetResult();
    double GetLength();
};

#endif
