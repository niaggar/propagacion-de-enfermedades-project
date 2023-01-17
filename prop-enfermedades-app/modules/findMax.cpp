#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "modules.h"

using namespace std;

double *Maximum(string name_data, PopulationType p)
{
    ifstream file;
    file.open("./data/" + name_data + ".dat");

    int col = p;
    double maximum;
    double day;
    string line_readed = "";

    if (!file)
        cout << "Error al abrir el fichero" << endl;

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
                if (resultado[col] > maximum)
                    {
                    maximum = resultado[col];
                    day = resultado[0];
                    }
                count++;
            }
            
        }
        file.close();
    }

    return new double[2]{maximum, day};
}
