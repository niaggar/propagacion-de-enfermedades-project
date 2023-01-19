#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "modules/methods/Runge4.h"
#include "modules/program/program.h"
#include "modules/program/control/Control.h"
#include "modules/methods/models/SirModel.h"

using namespace std;

int main()
{
    double dt = 0.1;
    double tmax = 100.0;
    double t = 0.0;
    double s = 0.99;
    double i = 0.01;
    double r = 0.0;



    SirModel *model = new SirModel();
    Runge4 *runge4 = new Runge4();

    model->SetParameters(0.5, 0.1);
    
    runge4->SetModel(model);
    runge4->DoMethod(t, dt, s, i, r, tmax);
    
    double **data = runge4->GetResult();
    int n = runge4->GetLength();

    WriteData("data", data, n);

    double *max_suceptibles = Maximum("data", PopulationType::Infected);
    cout << max_suceptibles[0] << " " << max_suceptibles[1] << endl;

    return 0;
}
