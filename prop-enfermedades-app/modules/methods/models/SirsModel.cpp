#include "SirsModel.h"

SirsModel::SirsModel() {}

void SirsModel::SetParameters(double m, double b, double v)
{
    this->m = m;
    this->b = b;
    this->v = v;
}

double SirsModel::Susceptible(double t, double s, double i, double r)
{
    return (-(b *s *i) - (m * s) + (m * N));
}

double SirsModel::Infected(double t, double s, double i, double r)
{
    return ((b * s *i) - (v * i) - (m * i));
}

double SirsModel::Removed(double t, double s, double i, double r)
{
    return ((v * i) - (m * r));
}

double SirsModel::GetM()
{
    return this->m;
}

double SirsModel::GetB()
{
    return this->b;
}

double SirsModel::GetV()
{
    return this->v;
}
