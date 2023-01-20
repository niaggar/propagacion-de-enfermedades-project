#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "modules/methods/Runge4.h"
#include "modules/program/program.h"
#include "modules/program/images/Images.h"
#include "modules/program/control/Control.h"
#include "modules/methods/models/SirModel.h"

using namespace std;

int main()
{
    Control *control = new Control();
    double dt = control->GetDouble("Cual es el tamano de paso? (dt)");
    double tmax = control->GetDouble("Cual es el tiempo maximo? (dias)");
    double t = control->GetDouble("Cual es el tiempo inicial? (dias)");
    
    double S = control->GetInt("Cual es la poblacion inicial SUCEPTIBLE? (# personas)");
    double I = control->GetDouble("Cual es la poblacion inicial INFECTADA? (# personas)");
    double R = control->GetDouble("Cual es la poblacion inicial REMOVIDA? (# personas)");

    int N = S + I + R;
    double s = S / N;
    double i = I / N;
    double r = R / N;    



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


    Images *images = new Images();
    images->GenerateBasicPlot("./data/data.dat", "./img/result/data1.png");
    images->GeneratePanelesPlot("./data/data.dat", "./img/result/data2.png");


    return 0;
}
