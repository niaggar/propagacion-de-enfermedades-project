#include <iostream>
#include <fstream>
#include <string>
#include "../../data/data.dat"

using namespace std;

double Maximum(char name_data)
{
    ifstream file;
    file.open("../../data/" + name_data);

    int data;
    double maximum;

    if (!file)
        cout << "Error al abrir el fichero" << endl;

    else
        {
        while (file >> data)
            if (data > maximum)
                maximum = data;
            else     
            file.close();
        }
    return maximum; 
}


