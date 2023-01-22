#include "Images.h"

Images::Images()
{
    // ctor
}

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
