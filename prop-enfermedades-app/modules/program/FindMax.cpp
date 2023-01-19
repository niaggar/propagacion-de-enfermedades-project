#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "program.h"

using namespace std;

/// @brief Funcion que determina el dia y el valor maximo de una poblacion
/// @param name_data Nombre del fichero
/// @param p Tipo de poblacion
/// @return Array con el valor maximo y el dia. [0] = valor maximo, [1] = dia
double *Maximum(string name_data, PopulationType p = PopulationType::Infected)
{
    double maximum;
    double day;

    double **populationValues = ReadData(name_data, p);
    int len = populationValues[2][0];

    for (int i = 0; i < len; i++)
    {
        if (populationValues[1][i] > maximum)
        {
            maximum = populationValues[1][i];
            day = populationValues[0][i];
        }
    }

    return new double[2] { maximum, day };
}
