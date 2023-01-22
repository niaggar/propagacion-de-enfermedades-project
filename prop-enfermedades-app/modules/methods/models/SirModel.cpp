#include "SirModel.h"

SirModel::SirModel()
{
    this->modelType = ModelType::SIR;
    this->modelName = "SIR";
    this->modelDescription = "Modelo SIR, que representa la propagación de una enfermedad infecciosa en una población.";
    this->modelEquations = "S' = -b * S * I \\\\ I' = b * S * I - k * I \\\\ R' = k * I";
    this->modelParameters = { "b", "k" };
}

void SirModel::SetParameters(vector<double> values)
{
    this->b = values[0];
    this->k = values[1];
}

double SirModel::Susceptible(double t, double s, double i, double r)
{
    return -(b * s * i);
}

double SirModel::Infected(double t, double s, double i, double r)
{
    return (b * s * i) - (k * i);
}

double SirModel::Removed(double t, double s, double i, double r)
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
