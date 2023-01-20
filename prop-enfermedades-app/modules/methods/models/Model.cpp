#include "Model.h"
#include <iostream>

using namespace std;

Model::Model()
{
    cout << "Model created" << endl;
}

Model::Model(int n)
{
    this->N = n;
}

void Model::SetN(int n)
{
    this->N = n;
}

double Model::Susceptible(double t, double s, double i, double r)
{
    return 0.0;
}

double Model::Infected(double t, double s, double i, double r)
{
    return 0.0;
}

double Model::Removed(double t, double s, double i, double r)
{
    return 0.0;
}
