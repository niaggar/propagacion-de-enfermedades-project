#include "SirsVacModel.h"

SirsVacModel::SirsVacModel()
{
    this->modelType = ModelType::SIRSV;
    this->modelName = "SIRSV";
}

void SirsVacModel::SetParameters(vector<double> parameters)
{
    this->m = parameters[0];
    this->b = parameters[1];
    this->v = parameters[2];
    this->g1 = parameters[3];
    this->g2 = parameters[4];
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

