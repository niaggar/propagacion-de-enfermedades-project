#ifndef PROGRAM_H
#define PROGRAM_H

#include "../enums/enums.h"
#include "../methods/models/Models.h"
#include <string>

using namespace std;

void WriteData(string, double **, int);
double **ReadData(string, PopulationType);
double *Maximum(string a, PopulationType b);
double *Maximum(double **, PopulationType b);
void Phase(string name_data, Model *);
void Contour(string projectRoute, Model *model, vector<double> initialValues);

#endif
