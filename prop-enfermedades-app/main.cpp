#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "modules/modules.h"
#include "modules/methods/methods.h"
#include "modules/methods/Runge4.h"
#include "modules/program/program.h"


using namespace std;

int main()
{
    double t = 0.0;
    double s = 0.99;
    double i = 0.01;
    double r = 0.0;
    double b = 0.5;
    double g = 0.1;

    double dt = 0.1;
    double tmax = 100.0;

    ofstream file;
    file.open("./data/data.dat");

    Runge4 *runge4 = new Runge4(b, g, Suceptibles, Infectados, Recuperados);

    while (t < tmax)
    {
        double *result = runge4->Calc(t, dt, s, i, r);

        s = result[0];
        i = result[1];
        r = result[2];

        file << t << " " << s << " " << i << " " << r << endl;
    
        t += dt;
    }

    double *max_suceptibles = Maximum("data", PopulationType::Infected);
    cout << max_suceptibles[0] << max_suceptibles[1] << endl;
    return 0;
}
