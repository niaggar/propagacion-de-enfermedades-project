#include "SirsVacModel.h"

SirsVacModel::SirsVacModel() {}

void SirsVacModel::SetParameters(double m, double K, double b, double d, double v, double e, double g, function<double(double)> u)
{
    this->m = m;
    this->K = K;
    this->b = b;
    this->d = d;
    this->v = v;
    this->e = e;
    this->g = g;
    this->u = u;
}

double SirsVacModel::Susceptible(double t, double s, double i, double r)
{
    return -m * (1 - s/K) - b * s *i - (d + u(t)) * s + v * r;
}

double SirsVacModel::Infected(double t, double s, double i, double r)
{
    return b * s * i - (d + e + g) * i;
}

double SirsVacModel::Removed(double t, double s, double i, double r)
{
    return g * i - (d + v) * r + u(t) * s;
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

double SirsVacModel::GetG()
{
    return this->g;
}
