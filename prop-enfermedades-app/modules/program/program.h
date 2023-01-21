#ifndef PROGRAM_H
#define PROGRAM_H

#include "../enums/enums.h"
#include <string>

using namespace std;

void WriteData(string, double **, int);
double **ReadData(string, PopulationType);
double *Maximum(string a, PopulationType b);
double *Maximum(double **, PopulationType b);
void Phase(string name_data, ModelType);

#endif
