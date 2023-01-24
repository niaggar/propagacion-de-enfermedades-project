#include "program.h"


/// @brief Funcion que grafica la poblacion en funcion de los parametros
/// @param projectRoute Nombre de la ruta
/// @param initialConditions Va
/// @return Gif de la poblacion en funcion de los parametros a lo largo del tiempo
void Contour(string projectRoute, vector<double> initialConditions)
{
    SirModel*model = new SirModel();

    double kmax = 0.6;
    double kmin = 0.1;
    double bmax = 2.0;
    double bmin = 0.5;

    double *constants = new double[3];
    constants[0] = bmin;
    constants[1] = kmin;

    int n_const = 10;
    double dk = (kmax - kmin) / n_const;
    double db = (bmax - bmin) / n_const;

    double s0 = initialConditions[0];
    double i0 = initialConditions[1];
    double r0 = initialConditions[2];

    double t0 = 0;
    double tmax = 100;

    int n_runge = 100;
    double dt = (int)((tmax - t0) / n_runge);

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

    t = t0;



    string contourData = projectRoute + "/contourData";
    mkdir(contourData.c_str(), 0777);

    for (int ti = 0; ti < n_runge; ti++)
    {
        ofstream file;
        file.open(contourData + "/contour-" + to_string(ti) + ".dat");

        constants[0] = bmin;
        for (int bi = 0; bi <= n_const; bi++) // i = b
        {
            constants[1] = kmin;

            for (int ki = 0; ki <= n_const; ki++) // j = k
            {
                s = inmediatamenteAnteriores[ti][bi][ki][0];
                i = inmediatamenteAnteriores[ti][bi][ki][1];
                r = inmediatamenteAnteriores[ti][bi][ki][2];
                file << constants[0] << " " << constants[1] << " " << s  << " " << i  << " " << r  << endl;
                
                Runge4 *runge4 = new Runge4();
                vector<double> constantsV = { constants[0], constants[1] };

                model->SetParameters(constantsV);
                runge4->SetModel(model);
                double *actuales = runge4->Calc(t, dt, s, i, r);

                inmediatamenteAnteriores[ti + 1][bi][ki][0] = actuales[0];
                inmediatamenteAnteriores[ti + 1][bi][ki][1] = actuales[1];
                inmediatamenteAnteriores[ti + 1][bi][ki][2] = actuales[2];
                constants[1] = constants[1] + dk;

                delete runge4;
            }

            file << endl;            

            constants[0] = constants[0] + db;
        }
        
        t = t + dt;
    }

    string contourImageFolder = projectRoute + "/contourImage";
    mkdir(contourImageFolder.c_str(), 0777);

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    for (int i = 0; i < n_runge; i++)
    {
        int n = 3;
        string number = to_string(i);
        number.insert(0, n - min(n, (int)number.size()), '0');

        string cotourRoute = contourData + "/contour-" + to_string(i) + ".dat";
        string imgRoute = contourImageFolder + "/contour-" + number + ".png";

        fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1000,1900\n");
        // set terminal to gif
        // fprintf(gnuplotPipe, "set terminal gif animate delay 10 size 1000,1900\n");
        fprintf(gnuplotPipe, "set output \"%s\"\n", imgRoute.c_str());
        fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
        fprintf(gnuplotPipe, "set xlabel \"Parámetro b\"\n");
        fprintf(gnuplotPipe, "set ylabel \"Parámetro k\"\n");
        fprintf(gnuplotPipe, "set zlabel \"Poblacion\"\n");
        // Set title to the plot in the format "t = 0.000000"
        fprintf(gnuplotPipe, "set title \"Tiepo transcurrido t = %i dia\"\n", i);

        fprintf(gnuplotPipe, "set xrange [%f:%f]\n", bmin, bmax);
        fprintf(gnuplotPipe, "set yrange [%f:%f]\n", kmin, kmax);
        fprintf(gnuplotPipe, "set zrange [%f:%f]\n", 0.0, 1.0);
        fprintf(gnuplotPipe, "set palette rgb 23,28,3\n");
        fprintf(gnuplotPipe, "set grid\n");
        fprintf(gnuplotPipe, "set multiplot layout 3,1\n");
        fprintf(gnuplotPipe, "set isosamples 30,30\n");
        fprintf(gnuplotPipe, "splot \"%s\" u 1:2:3 w pm3d title \"Suceptibles\"\n", cotourRoute.c_str());
        fprintf(gnuplotPipe, "splot \"%s\" u 1:2:4 w pm3d title \"Infectados\"\n", cotourRoute.c_str());
        fprintf(gnuplotPipe, "splot \"%s\" u 1:2:5 w pm3d title \"Removidos\"\n", cotourRoute.c_str());
        fprintf(gnuplotPipe, "unset multiplot\n");
        fflush(gnuplotPipe);
    }
    pclose(gnuplotPipe);

    // Para crear un video:
    // ffmpeg -framerate 5 -pattern_type glob -i './iquepues/contourImage/*.png' -c:v libx264 -vf fps=15 -pix_fmt yuv420p output-video2.mp4
    // ffmpeg -i input.mp4 output.gif

    string ffmpegVideCommand = "ffmpeg -framerate 5 -pattern_type glob -i '" + contourImageFolder + "/*.png' -c:v libx264 -vf fps=15 -pix_fmt yuv420p " + projectRoute + "/contour-video.mp4";
    string ffmpegGifCommand = "ffmpeg -i " + projectRoute + "/contour-video.mp4 " + projectRoute + "/contour-video.gif";

    system(ffmpegVideCommand.c_str());
    system(ffmpegGifCommand.c_str());


    // string command = "convert -resize 60% -delay 10 -loop 0 " + contourImageFolder + "/contour-*.gif " + projectRoute + "/basic.gif";
    // system(command.c_str());
}


