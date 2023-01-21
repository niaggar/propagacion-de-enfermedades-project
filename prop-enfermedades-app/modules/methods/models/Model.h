#ifndef MODEL_H
#define MODEL_H

#include <vector>

using namespace std;

/// @brief Clase abstracta que representa un modelo
class Model
{
    private:

    protected:
        int N;
    public:
        Model();
        Model(int);
        
        virtual void SetN(int);
        virtual void SetParameters(vector<double>);
        virtual double Susceptible(double t, double s, double i, double r);
        virtual double Infected(double t, double s, double i, double r);
        virtual double Removed(double t, double s, double i, double r);
};

#endif
