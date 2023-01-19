#ifndef SIRMODEL_H
#define SIRMODEL_H

#include "Model.h"

class SirModel : public Model
{
    private:
        double b;
        double k;
    public:
        SirModel();

        void SetParameters(double b, double k);

        double Susceptible(double t, double s, double i, double r) override;
        double Infected(double t, double s, double i, double r) override;
        double Recovered(double t, double s, double i, double r) override;

        double GetB();
        double GetK();
};

#endif
