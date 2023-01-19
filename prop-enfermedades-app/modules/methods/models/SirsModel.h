#ifndef SIRSMODEL_H
#define SIRSMODEL_H

#include "Model.h"

class SirsModel : public Model
{
    private:
        double m;
        double K;
        double b;
        double d;
        double v;
        double e;
        double r;
    public:
        SirsModel();

        void SetParameters(double m, double K, double b, double d, double v, double e, double r);

        double Susceptible(double t, double s, double i, double r) override;
        double Infected(double t, double s, double i, double r) override;
        double Recovered(double t, double s, double i, double r) override;

        double GetM();
        double GetK();
        double GetB();
        double GetD();
        double GetV();
        double GetE();
        double GetR();
};

#endif
