#include "SirsModel.h"

SirsModel::SirsModel()
{
    this->modelType = ModelType::SIRS;
    this->modelName = "SIRS";
}

void SirsModel::SetParameters(vector<double> parameters)
{
    this->m = parameters[0];
    this->b = parameters[1];
    this->v = parameters[2];
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
