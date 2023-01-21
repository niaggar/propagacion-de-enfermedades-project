#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "modules/methods/Runge4.h"
#include "modules/program/program.h"
#include "modules/program/images/Images.h"
#include "modules/program/control/Control.h"
#include "modules/methods/models/SirModel.h"
#include "modules/methods/models/SirsModel.h"
#include "modules/methods/models/SirsVacModel.h"

using namespace std;

int main()
{
    Control *control = new Control();
    control->Run();



//     double dt = control->GetDouble("Cual es el tamano de paso? (dt)");
//     double tmax = control->GetDouble("Cual es el tiempo maximo? (dias)");
//     double t = control->GetDouble("Cual es el tiempo inicial? (dias)");
    
//     double S = control->GetInt("Cual es la poblacion inicial SUCEPTIBLE? (# personas)");
//     double I = control->GetDouble("Cual es la poblacion inicial INFECTADA? (# personas)");
//     double R = control->GetDouble("Cual es la poblacion inicial REMOVIDA? (# personas)");

//     int N = S + I + R;
//     double s = S / N;
//     double i = I / N;
//     double r = R / N;    


//     //SIR MODEL---------------------

//     SirModel *model_1 = new SirModel();
//     model_1->SetN(N);
//     Runge4 *runge4_1 = new Runge4();

//     model_1->SetParameters(0.5 / N, 0.1);
    
//     cout << 0.5 / N << " " << 0.1 << endl;

//     runge4_1->SetModel(model_1);
//     runge4_1->DoMethod(t, dt, S, I, R, tmax);
    
//     double **dataSir = runge4_1->GetResult();
//     int n_1 = runge4_1->GetLength();

//     WriteData("dataSir", dataSir, n_1);

//     //SIRS MODEL--------------------

//     SirsModel *model_2 = new SirsModel();
//     model_2->SetN(N);
//     Runge4 *runge4_2 = new Runge4();

//     model_2->SetParameters(0.0625 , 0.5 / N, 0.1);
    
//     runge4_2->SetModel(model_2);
//     runge4_2->DoMethod(t, dt, S, I, R, tmax);
    
//     double **dataSirs = runge4_2->GetResult();
//     int n_2 = runge4_2->GetLength();

//     WriteData("dataSirs", dataSirs, n_2);

//    //SIRS-VAC MODEL--------------------

//     SirsVacModel *model_3 = new SirsVacModel();
//     model_3->SetN(N);
//     Runge4 *runge4_3 = new Runge4();

//     model_3->SetParameters(0.0625, 0.5 / N, 0.1, 0.05, 0.04);
    
//     runge4_3->SetModel(model_3);
//     runge4_3->DoMethod(t, dt, S, I, R, tmax);
    
//     double **dataSirsVac = runge4_3->GetResult();
//     int n_3 = runge4_3->GetLength();

//     WriteData("dataSirsVac", dataSirsVac, n_3);

//     //FIND MAX------------------------------------------------------------

//     double *max_suceptibles_Sir = Maximum("dataSir", PopulationType::Infected);
//     cout << "Max suceptibles Sir" << " " << max_suceptibles_Sir[0] << " " << max_suceptibles_Sir[1] << endl;

//     double *max_suceptibles_Sirs = Maximum("dataSirs", PopulationType::Infected);
//     cout << "Max suceptibles Sirs" << " " << max_suceptibles_Sirs[0] << " " << max_suceptibles_Sirs[1] << endl;

//     double *max_suceptibles_SirsVac = Maximum("dataSirsVac", PopulationType::Infected);
//     cout << "Max suceptibles SirVac" << " " << max_suceptibles_SirsVac[0] << " " << max_suceptibles_SirsVac[1] << endl;


//     //CREATE IMAGES-------------------------------------------------------

//     Images *images_1 = new Images();
//     images_1->GenerateBasicPlot("./data/dataSir.dat", "./img/result/Sirdata1.png");
//     images_1->GeneratePanelesPlot("./data/dataSir.dat", "./img/result/Sirdata2.png");

//     Images *images_2 = new Images();
//     images_2->GenerateBasicPlot("./data/dataSirs.dat", "./img/result/Sirsdata1.png");
//     images_2->GeneratePanelesPlot("./data/dataSirs.dat", "./img/result/Sirsdata2.png");

//     Images *images_3 = new Images();
//     images_3->GenerateBasicPlot("./data/dataSirsVac.dat", "./img/result/SirsVacdata1.png");
//     images_3->GeneratePanelesPlot("./data/dataSirsVac.dat", "./img/result/SirsVacdata2.png");

//     //---------------------------------------------------------------------

    return 0;
}
