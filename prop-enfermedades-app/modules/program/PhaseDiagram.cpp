#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "program.h"
#include "./images/Images.h"

using namespace std;

/// @brief Funcion que crea el diagrama de fase de una poblacion
/// @param projectRoute Nombre de la ruta
/// @param model Modelo de la poblacion
/// @return Grafica de la derivada de la poblacion contra la poblacion
void Phase(string projectRoute, Model *model)
{
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
    
    file.close();

    Images *images = new Images();
    images->GeneratePhasePlot(PhaseDataRoute, projectRoute + "/phase-" + model->modelName + ".png");
}

