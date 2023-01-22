#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "program.h"
#include "./images/Images.h"
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
void Phase(string projectRoute, ModelType modelType)
{
    Model *model;
    switch (modelType)
    {
    case ModelType::SIR:
        model = new SirModel();
        break;
    case ModelType::SIRS:
        model = new SirsModel();
        break;
    case ModelType::SIRSV:
        model = new SirsVacModel();
        break;
    }

    string name_data = projectRoute + "/result-" + model->modelName + ".dat";
    double **infValues = ReadData(name_data, PopulationType::Infected);
    double **sucValues = ReadData(name_data, PopulationType::Susceptible);
    double **remValues = ReadData(name_data, PopulationType::Removed);

    cout << name_data << endl;
    cout << endl;
    cout << infValues[2][0] << " " << sucValues[2][0] << " " << remValues[2][0] << endl;

    int len = infValues[2][0];

    cout << "len: " << len << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    double *listDS = new double[len];
    double *listDI = new double[len];
    double *listDR = new double[len];
    for (int i = 0; i < len; i++)
    {
        double dS = model->Susceptible(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);
        double dI = model->Infected(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);
        double dR = model->Removed(infValues[0][i], sucValues[1][i], infValues[1][i], remValues[1][i]);

        cout << dS << " " << dI << " " << dR << endl;

        listDS[i] = dS;
        listDI[i] = dI;
        listDR[i] = dR;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    ofstream file;
    string PhaseDataRoute = projectRoute + "/phase-" + model->modelName + ".dat";
    file.open(PhaseDataRoute);
    for (int i = 0; i < len; i++)
        file << sucValues[1][i] << " " << listDS[i] << " " << infValues[1][i] << " " << listDI[i] << " " << remValues[1][i] << " " << listDR[i] << endl;

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", (projectRoute + "/phase-" + model->modelName + ".png").c_str());
    fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
    fprintf(gnuplotPipe, "set xlabel \"Población / Población total  = P\"\n");
    fprintf(gnuplotPipe, "set ylabel \"DP/dt\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\", \"%s\" using 3:4 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 5:6 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", PhaseDataRoute.c_str(), PhaseDataRoute.c_str(), PhaseDataRoute.c_str());
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

