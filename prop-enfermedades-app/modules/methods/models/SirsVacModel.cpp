#include "SirsVacModel.h"

SirsVacModel::SirsVacModel() {}

void SirsVacModel::SetParameters(double m, double b, double v, double g1, double g2)
{
    this->m = m;
    this->b = b;
    this->v = v;
    this->g1 = g1;
    this->g2 = g2;
}

double SirsVacModel::Susceptible(double t, double s, double i, double r)
{
    return (-(b * s * i) - (m * s) + (m * N) - (g1 * (m * N)) - (g2 * s));
}

double SirsVacModel::Infected(double t, double s, double i, double r)
{
    return ((b * s * i) - (v * i) - (m * i));
}

double SirsVacModel::Removed(double t, double s, double i, double r)
{
    return ((v * i) - (m * r) + g1 * (m *N) + (g2 * s));
}

double SirsVacModel::GetM()
{
    return this->m;
}

double SirsVacModel::GetB()
{
    return this->b;
}

double SirsVacModel::GetV()
{
    return this->v;
}

double SirsVacModel::GetG1()
{
    return this->g1;
}

double SirsVacModel::GetG2()
{
    return this->g2;
}

