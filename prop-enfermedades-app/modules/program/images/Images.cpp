#include "Images.h"

Images::Images() {}

void Images::GenerateBasicPlot(string DataRoute, string filename)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", filename.c_str());
    fprintf(gnuplotPipe, "set title \"Comportamiento de las poblaciones\"\n");
    fprintf(gnuplotPipe, "set xlabel \"Tiempo (Días)\"\n");
    fprintf(gnuplotPipe, "set ylabel \"Población / Población total\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\", \"%s\" using 1:3 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 1:4 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", DataRoute.c_str(), DataRoute.c_str(), DataRoute.c_str());
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

void Images::GeneratePanelesPlot(string DataRoute, string filename)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", filename.c_str());
    fprintf(gnuplotPipe, "set title \"Comportamiento de las poblaciones\"\n");
    fprintf(gnuplotPipe, "set xlabel \"Tiempo (Días)\"\n");
    fprintf(gnuplotPipe, "set ylabel \"Población / Población total\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set multiplot layout 2,2\n");
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\", \"%s\" using 1:3 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 1:4 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", DataRoute.c_str(), DataRoute.c_str(), DataRoute.c_str());
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\"\n", DataRoute.c_str());
    fprintf(gnuplotPipe, "plot \"%s\" using 1:3 w l lw 4 lc \"#2e282a\" title \"Infected\"\n", DataRoute.c_str());
    fprintf(gnuplotPipe, "plot \"%s\" using 1:4 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", DataRoute.c_str());

    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

void Images::GeneratePhasePlot(string DataRoute, string filename)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
    fprintf(gnuplotPipe, "set output \"%s\"\n", filename.c_str());
    fprintf(gnuplotPipe, "set title \"Diagrama de fase\"\n");
    fprintf(gnuplotPipe, "set xlabel \"Población / Población total  = P\"\n");
    fprintf(gnuplotPipe, "set ylabel \"DP/dt\"\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot \"%s\" using 1:2 w l lw 4 lc \"#17bebb\" title \"Suceptibles\", \"%s\" using 3:4 w l lw 4 lc \"#2e282a\" title \"Infected\", \"%s\" using 5:6 w l lw 4 lc \"#cd5334\" title \"Recovered\"\n", DataRoute.c_str(), DataRoute.c_str(), DataRoute.c_str());
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

void Images::GererateBasicGif(Model * model, string projectRoute, int size, double startTime, double maxTime, double maxPopulation)
{
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    int n = 3;
    string number, range, imageName;
    string imageTemp = projectRoute + "/imgTemp";
    string dataRoute = projectRoute + "/result-" + model->modelName + ".dat";

    mkdir(imageTemp.c_str(), 0777);

    for (int i = 0; i < size; i++)
    {
        number = to_string(i);
        number.insert(0, n - min(n, (int)number.size()), '0');
        range = "every ::" + to_string(0) + "::" + to_string(i);
        imageName = imageTemp + "/basic-" + number;

        fprintf(gnuplotPipe, "set terminal pngcairo enhanced color size 1200,800\n");
        fprintf(gnuplotPipe, "set output \"%s.png\"\n", imageName.c_str());
        fprintf(gnuplotPipe, "set title \"Comportamiento de las poblaciones\"\n");
        fprintf(gnuplotPipe, "set xrange [%f:%f]\n", startTime, maxTime);
        fprintf(gnuplotPipe, "set yrange [0:%f]\n", maxPopulation);
        fprintf(gnuplotPipe, "set xlabel \"Tiempo (Días)\"\n");
        fprintf(gnuplotPipe, "set ylabel \"Población / Población total\"\n");
        fprintf(gnuplotPipe, "set grid\n");
        fprintf(gnuplotPipe, "plot \"%s\" %s i 0 u 1:2 w lp ps 1 pt 6 lc \"#17bebb\" title \"Suceptibles\"\n", dataRoute.c_str(), range.c_str());
        fprintf(gnuplotPipe, "unset output\n");
        fflush(gnuplotPipe);
    }

    pclose(gnuplotPipe);

    string command = "convert -delay 10 -loop 0 " + imageTemp + "/basic-*.png " + projectRoute + "/basic.gif";
    system(command.c_str());
}
