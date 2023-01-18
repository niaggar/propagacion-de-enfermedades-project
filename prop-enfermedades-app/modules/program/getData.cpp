#include <string>
#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "../enums/enums.h"

using namespace std;

double *GetData(string fileName, PopulationType populationType)
{
    ifstream file;
    list<double> data;
    string line_readed = "";

    file.open("./data/" + fileName + ".dat");

    if (!file)
    {
        cout << "Error al abrir el fichero" << endl;
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
            }

            data.push_back(resultado[populationType]);
        }

        file.close();
    }

    double *data_array = new double[data.size()];
    copy(data.begin(), data.end(), data_array);
}
