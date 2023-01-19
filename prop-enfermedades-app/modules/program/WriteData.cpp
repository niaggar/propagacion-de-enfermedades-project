#include <iostream>
#include <fstream>
#include <string>
#include "program.h"

using namespace std;

/// @brief Funcion que escribe los datos de una poblacion en un fichero
/// @param fileName Nombre del fichero
/// @param data Datos resultantes del modelo [0] = tiempo, [1] = sucectible, [2] = infectado, [3] = removido
/// @param size Tamaño de los datos resultantes
void WriteData(string fileName, double **data, int size)
{
    ofstream file;
    file.open("./data/" + fileName + ".dat");

    for (int i = 0; i < size; i++)
    {
        file << data[0][i] << " " << data[1][i] << " " << data[2][i] << endl;
    }

    file.close();
}
