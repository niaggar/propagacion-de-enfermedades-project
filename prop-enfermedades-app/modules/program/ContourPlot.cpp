#include "program.h"


/// @brief Funcion que grafica la poblacion en funcion de los parametros
/// @param projectRoute Nombre de la ruta
/// @param initialConditions Va
/// @return Gif de la poblacion en funcion de los parametros a lo largo del tiempo
void Contour(string projectRoute, vector<double> initialConditions)
{
    SirModel *model = new SirModel();

    double kmax = 0.6;
    double kmin = 0.1;
    double bmax = 2.0;
    double bmin = 0.5;

    double *constants = new double[2];
    constants[0] = kmin;
    constants[1] = bmin;

    int n_const = 10;
    double dk = (kmax - kmin) / n_const;
    double db = (bmax - bmin) / n_const;

    double s0 = initialConditions[0];
    double i0 = initialConditions[1];
    double r0 = initialConditions[2];
    double N = s0 + i0 + r0;

    double t0 = initialConditions[3];
    double tmax = initialConditions[4];
    double dt = initialConditions[5];

    int n_runge = (int)((tmax - t0) / dt);

    double ****inmediatamenteAnteriores = new double ***[n_runge + 1];
    for (int ti = 0; ti <= n_runge; ti++)
    {
        inmediatamenteAnteriores[ti] = new double **[n_const + 1];
        for (int bi = 0; bi <= n_const; bi++)
        {
            inmediatamenteAnteriores[ti][bi] = new double *[n_const + 1];
            for (int ki = 0; ki <= n_const; ki++)
            {
                inmediatamenteAnteriores[ti][bi][ki] = new double[3];
                inmediatamenteAnteriores[ti][bi][ki][0] = 0;
                inmediatamenteAnteriores[ti][bi][ki][1] = 0;
                inmediatamenteAnteriores[ti][bi][ki][2] = 0;
            }
        }
    }

    double s, i, r, t;
    for (int bi = 0; bi <= n_const; bi++) // i = b
    {
        for (int ki = 0; ki <= n_const; ki++) // j = k
        {
            inmediatamenteAnteriores[0][bi][ki][0] = s0;
            inmediatamenteAnteriores[0][bi][ki][1] = i0;
            inmediatamenteAnteriores[0][bi][ki][2] = r0;
        }
    }



    string contourData = projectRoute + "/contourData";
    mkdir(contourData.c_str(), 0777);

    for (int ti = 0; ti <= n_runge; ti++)
    {
        ofstream file;
        file.open(contourData + "/contour-" + to_string(ti) + ".dat");

        constants[1] = bmin;
        for (int bi = 0; bi <= n_const; bi++) // i = b
        {
            constants[0] = kmin;

            for (int ki = 0; ki <= n_const; ki++) // j = k
            {
                s = inmediatamenteAnteriores[ti][bi][ki][0];
                i = inmediatamenteAnteriores[ti][bi][ki][1];
                r = inmediatamenteAnteriores[ti][bi][ki][2];

                file << constants[0] << " " << constants[1] << " " << s  << " " << i  << " " << r  << endl;
                
                Runge4 *runge4 = new Runge4();
                vector<double> constantsV = { constants[0], constants[1] };

                cout << "t: " << t << " dt: " << dt << " s: " << s << " i: " << i << " r: " << r << endl;
                cout << "k: " << constantsV[0] << " b: " << constantsV[1] << endl;

                model->SetParameters(constantsV);
                runge4->SetModel(model);
                double *actuales = runge4->Calc(t, dt, s, i, r);

                
                inmediatamenteAnteriores[ti][bi][ki][0] = actuales[0];
                inmediatamenteAnteriores[ti][bi][ki][1] = actuales[1];
                inmediatamenteAnteriores[ti][bi][ki][2] = actuales[2];
                constants[0] = constants[0] + dk;

                delete runge4;
            }

            constants[1] = constants[1] + db;
        }
        
        t = t + dt;
    }
}

//     FILE *gnuplotPipe = popen("gnuplot -persist", "w");
//     fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
//     fprintf(gnuplotPipe, "set output \"%s\"\n", (projectRoute + "/phase-" + model->modelName + ".png").c_str());
//     fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
//     fprintf(gnuplotPipe, "set xlabel \"Parámetro b\"\n");
//     fprintf(gnuplotPipe, "set ylabel \"Parámetro k\"\n");
//     fprintf(gnuplotPipe, "set zlabel \"Poblacion\"\n");
//     fprintf(gnuplotPipe, "set grid\n");
//     fprintf(gnuplotPipe, "splot \"%s\" u 1:2:3 w pm3d title \"Suceptibles\", \"%s\" using 3:4 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 5:6 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", contour_data.c_str(), contour_data.c_str(), contour_data.c_str());
//     fflush(gnuplotPipe);
//     pclose(gnuplotPipe);
// }

// set xlabel 'Nombre del eje'
// set ylabel 'Nombre del eje'
// set zlabel 'Nombre del eje'

// splot 'datos.dat' w pm3d
