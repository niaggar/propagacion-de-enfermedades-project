#ifndef SIRSVACMODEL_H
#define SIRSVACMODEL_H

#include <functional>
#include "Model.h"

using namespace std;

class SirsVacModel : public Model
{
    private:
        double m;
        double K;
        double b;
        double d;
        function<double(double)> u;
        double v;
        double e;
        double r;
    public:
        SirsVacModel();

        void SetParameters(double m, double K, double b, double d, double v, double e, double r, function<double(double)> u);

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
