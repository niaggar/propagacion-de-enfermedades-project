#include "SirsVacModel.h"

SirsVacModel::SirsVacModel()
{
    this->modelType = ModelType::SIRSV;
    this->modelName = "SIRSV";
    this->modelDescription = "SIRSV model, which represents the spread of an infectious disease in a population considering births and deaths, in addition to vaccination.";
    this->modelEquations = "S' = -(b * S * I) - (m * S) + (m * N) - (g1 * (m * N)) - (g2 * S) \\\\ I' = (b * S * I) - (v * I) - (m * I) \\\\ R' = (v * I) - (m * R) + g1 * (m * N)";
    this->modelParameters = { "m", "b", "v", "g_1", "g_2" };
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

