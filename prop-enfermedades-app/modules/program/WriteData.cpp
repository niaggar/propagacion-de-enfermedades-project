#include <iostream>
#include <fstream>
#include <string>
#include "program.h"

using namespace std;

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
