#ifndef MODEL_H
#define MODEL_H

/// @brief Clase abstracta que representa un modelo
class Model
{
    private:
        /* data */
    public:
        Model();

        virtual double Susceptible(double t, double s, double i, double r);
        virtual double Infected(double t, double s, double i, double r);
        virtual double Removed(double t, double s, double i, double r);
};

#endif
