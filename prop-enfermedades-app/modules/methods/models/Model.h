#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "../../enums/enums.h"

using namespace std;

/// @brief Clase abstracta que representa un modelo
class Model
{
    protected:
        int N;
    public:
        Model();
        Model(int);

        ModelType modelType;
        string modelName;

        virtual void SetN(int);
        virtual void SetParameters(vector<double>);
        virtual double Susceptible(double t, double s, double i, double r);
        virtual double Infected(double t, double s, double i, double r);
        virtual double Removed(double t, double s, double i, double r);
};

#endif
