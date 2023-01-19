#include "SirsModel.h"

SirsModel::SirsModel() {}

void SirsModel::SetParameters(double m, double K, double b, double d, double v, double e, double r)
{
    this->m = m;
    this->K = K;
    this->b = b;
    this->d = d;
    this->v = v;
    this->e = e;
    this->r = r;
}

double SirsModel::Susceptible(double t, double s, double i, double r)
{
    return 0;
}

double SirsModel::Infected(double t, double s, double i, double r)
{
    return 0;
}

double SirsModel::Removed(double t, double s, double i, double r)
{
    return 0;
}

double SirsModel::GetM()
{
    return this->m;
}

double SirsModel::GetK()
{
    return this->K;
}

double SirsModel::GetB()
{
    return this->b;
}

double SirsModel::GetD()
{
    return this->d;
}

double SirsModel::GetV()
{
    return this->v;
}

double SirsModel::GetE()
{
    return this->e;
}

double SirsModel::GetR()
{
    return this->r;
}
