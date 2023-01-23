#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "control/Control.h"
#include "./images/Images.h"
#include "program.h"

using namespace std;

/// @brief Funcion que grafica la poblacion en funcion de los parametros
/// @param projectRoute Nombre de la ruta
/// @param model Modelo de la poblacion
/// @return Gif de la poblacion en funcion de los parametros a lo largo del tiempo
void Contour(string projectRoute, vector<double> initialValues)
{
    vector<double> constants;
    constants[0] = 0.5;
    constants[1] = 0.1;

    SirModel *model = new SirModel(); 

    for(int i=0; i<=10; i++)
    {   for(int j=0; j<=10; j++)
        {
            model->SetParameters(constants);   
            Runge4 *runge4 = new Runge4();
            runge4->SetModel(model);
            runge4->DoMethod(initialValues);

            double **res = runge4->GetResult();
            int size = runge4->GetLength();

            string contour_data = projectRoute + "/result-" + model->modelName + to_string(j) + ";"+ to_string(i) + ".dat";
            WriteData(contour_data, res, size);

            delete runge4;
            constants[0]=constants[0]+0.1;
            constants[1]=constants[1]+0.1;
        }
    }      

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", (projectRoute + "/phase-" + model->modelName + ".png").c_str());
    fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
    fprintf(gnuplotPipe, "set xlabel \"Parámetro b\"\n");
    fprintf(gnuplotPipe, "set ylabel \"Parámetro k\"\n");
    fprintf(gnuplotPipe, "set zlabel \"Poblacion\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "splot \"%s\" u 1:2:3 w pm3d title \"Suceptibles\", \"%s\" using 3:4 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 5:6 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", contour_data.c_str(), contour_data.c_str(), contour_data.c_str());
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}



// set xlabel 'Nombre del eje'
// set ylabel 'Nombre del eje'
// set zlabel 'Nombre del eje'

// splot 'datos.dat' w pm3d
