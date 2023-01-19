#include "SirModel.h"

SirModel::SirModel() {}

void SirModel::SetParameters(double b, double k)
{
    this->b = b;
    this->k = k;
}

double SirModel::Susceptible(double t, double s, double i, double r)
{
    return -b * s * i;
}

double SirModel::Infected(double t, double s, double i, double r)
{
    return b * s * i - k * i;
}

double SirModel::Recovered(double t, double s, double i, double r)
{
    return k * i;
}

double SirModel::GetB()
{
    return b;
}

double SirModel::GetK()
{
    return k;
}