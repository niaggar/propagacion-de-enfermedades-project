#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Images.h"
#include "program.h"
#include "../methods/models/SirModel.h"
#include "../methods/models/SirsModel.h"
#include "../methods/models/SirsVacModel.h"


using namespace std;

/// @brief Funcion que crea el diagrama de fase de una poblacion
/// @param name_data Nombre del fichero
/// @param p Tipo de poblacion
/// @param s susceptibles
/// @param i infectados
/// @param r recuperados
/// @return Grafica de la derivada de la poblacion contra la poblacion


void Phase(string name_data)
{
    double **infValues = ReadData(name_data, PopulationType::Infected);
    double **sucValues = ReadData(name_data, PopulationType::Susceptible);
    double **remValues = ReadData(name_data, PopulationType::Removed);
    int len = infValues[2][0];

    SirModel *model = new SirModel();

    double *listDS = new double[len];
    double *listDI = new double[len];
    double *listDR = new double[len];
    for (int i = 0; i < len; i++)
    {
        double dS = model->Susceptible(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);
        double dI = model->Infected(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);
        double dR = model->Removed(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);

        listDS[i] = dS;
        listDI[i] = dI;
        listDR[i] = dR;
    }

    ofstream file;
    file.open("../../data/phase.dat"); 
    for (int i = 0; i < len; i++)
        file << infValues[1][i] << " " << listDI[i] << sucValues[1][i] << " " << listDS[i] << remValues[1][i] << " " << listDR[i];

//CREATE IMAGES---------------------------------------

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", name_data.c_str());
    fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
    fprintf(gnuplotPipe, "set xlabel \Population /Total  = P\"\n");
    fprintf(gnuplotPipe, "set ylabel \"DP/dt\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\", \"%s\" using 1:3 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 1:4 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", DataRoute.c_str(), DataRoute.c_str(), DataRoute.c_str());
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

