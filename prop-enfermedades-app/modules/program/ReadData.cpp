#include <string>
#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "program.h"

using namespace std;

/// @brief Metodo para la lectura de datos de un fichero y obtnener un array de datos de una poblacion
/// @param fileName Nombre del fichero
/// @param populationType Tipo de poblacion
/// @return Array de datos de una poblacion [0] = tiempo, [1] = poblacion
double **ReadData(string fileRoute, PopulationType populationType)
{
    ifstream file;
    
    list<double> dataPopulation;
    list<double> dataTime;

    string line_readed = "";
    int col = populationType;

    file.open(fileRoute);

    if (!file)
    {
        cout << "Error opening the file" << endl;
    }
    else
    {
        while (file)
        {
            getline(file, line_readed);

            double *resultado = new double[4];
            istringstream isstream(line_readed);
            string palabra;

            int count = 0;
            while (isstream >> palabra)
            {
                resultado[count] = stod(palabra);
                count++;
            }

            dataPopulation.push_back(resultado[col]);
            dataTime.push_back(resultado[0]);
        }

        file.close();
    }

    cout << dataPopulation.size() << endl;
    cout << dataTime.size() << endl;

    double *data_array = new double[dataPopulation.size()];
    double *time_array = new double[dataTime.size()];
    double *len = new double[1] { dataTime.size() * 1.0 };
    
    copy(dataPopulation.begin(), dataPopulation.end(), data_array);
    copy(dataTime.begin(), dataTime.end(), time_array);

    return new double*[3] { time_array, data_array, len };
}
