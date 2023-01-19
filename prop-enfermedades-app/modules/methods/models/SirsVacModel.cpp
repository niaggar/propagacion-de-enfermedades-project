#include "SirsVacModel.h"

SirsVacModel::SirsVacModel() {}

void SirsVacModel::SetParameters(double m, double K, double b, double d, double v, double e, double r, function<double(double)> u)
{
    this->m = m;
    this->K = K;
    this->b = b;
    this->d = d;
    this->v = v;
    this->e = e;
    this->r = r;
    this->u = u;
}

double SirsVacModel::Susceptible(double t, double s, double i, double r)
{
    return 0;
}

double SirsVacModel::Infected(double t, double s, double i, double r)
{
    return 0;
}

double SirsVacModel::Recovered(double t, double s, double i, double r)
{
    return 0;
}

double SirsVacModel::GetM()
{
    return this->m;
}

double SirsVacModel::GetK()
{
    return this->K;
}

double SirsVacModel::GetB()
{
    return this->b;
}

double SirsVacModel::GetD()
{
    return this->d;
}

double SirsVacModel::GetV()
{
    return this->v;
}

double SirsVacModel::GetE()
{
    return this->e;
}

double SirsVacModel::GetR()
{
    return this->r;
}
