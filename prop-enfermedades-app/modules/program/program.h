#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../methods/Runge4.h"
#include "../enums/enums.h"
#include "../methods/models/Models.h"

using namespace std;

void WriteData(string, double **, int);
double **ReadData(string, PopulationType);
double *Maximum(string a, PopulationType b);
double *Maximum(double **, PopulationType b);
void Phase(string name_data, Model *);
void Contour(string projectRoute, vector<double> initialValues);

#endif
