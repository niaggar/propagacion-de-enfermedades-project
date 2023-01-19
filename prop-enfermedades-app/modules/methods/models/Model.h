#ifndef MODEL_H
#define MODEL_H

class Model
{
    private:
        /* data */
    public:
        Model();

        virtual double Susceptible(double t, double s, double i, double r);
        virtual double Infected(double t, double s, double i, double r);
        virtual double Recovered(double t, double s, double i, double r);
};

#endif
