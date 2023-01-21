#include "Control.h"

Control::Control() {}


void Control::UseNewProject()
{
    string projectName = GetString("Introduzca el nombre del proyecto");
    string path = "./data/" + projectName;
    mkdir(path.c_str(), 0777);

    vector<double> constantsSIR = GetConstants(ModelType::SIR);
    vector<double> constantsSIRS = GetConstants(ModelType::SIRS);
    vector<double> constantsSIRSV = GetConstants(ModelType::SIRSV);
    vector<double> initialValues = GetInitialValues();






    SirModel *sirModel = new SirModel();
    sirModel->SetParameters(constantsSIR);

    SirsModel *sirsModel = new SirsModel();
    sirsModel->SetParameters(constantsSIRS);

    SirsVacModel *sirsvModel = new SirsVacModel();
    sirsvModel->SetParameters(constantsSIRSV);




    Runge4 *runge4 = new Runge4();
    runge4->SetModel(sirModel);
    runge4->DoMethod(initialValues);

    double **resSir = runge4->GetResult();
    int sizeSir = runge4->GetLength();

    runge4->SetModel(sirsModel);
    runge4->DoMethod(initialValues);

    double **resSirs = runge4->GetResult();
    int sizeSirs = runge4->GetLength();

    runge4->SetModel(sirsvModel);
    runge4->DoMethod(initialValues);

    double **resSirsv = runge4->GetResult();
    int sizeSirsv = runge4->GetLength();




    string pathResultSir = path + "/resultSir.dat";
    string pathResultSirs = path + "/resultSirs.dat";
    string pathResultSirsv = path + "/resultSirsv.dat";

    WriteData(pathResultSir, resSir, sizeSir);
    WriteData(pathResultSirs, resSirs, sizeSirs);
    WriteData(pathResultSirsv, resSirsv, sizeSirsv);





    Images *images = new Images();
    images->GenerateBasicPlot(pathResultSir, pathResultSir + ".png");
    images->GenerateBasicPlot(pathResultSirs, pathResultSirs + ".png");
    images->GenerateBasicPlot(pathResultSirsv, pathResultSirsv + ".png");






    // Guardar los datos en archivos
    string pathConstantsSIR = path + "/constantsSIR.txt";
    string pathConstantsSIRS = path + "/constantsSIRS.txt";
    string pathConstantsSIRSV = path + "/constantsSIRSV.txt";
    string pathInitialValues = path + "/initialValues.txt";
    
    ofstream fileConstSIR;
    fileConstSIR.open(pathConstantsSIR);
    for (int i = 0; i < constantsSIR.size(); i++)
    {
        fileConstSIR << constantsSIR[i] << endl;
    }
    fileConstSIR.close();

    ofstream fileConstSIRS;
    fileConstSIRS.open(pathConstantsSIRS);
    for (int i = 0; i < constantsSIRS.size(); i++)
    {
        fileConstSIRS << constantsSIRS[i] << endl;
    }
    fileConstSIRS.close();

    ofstream fileConstSIRSV;
    fileConstSIRSV.open(pathConstantsSIRSV);
    for (int i = 0; i < constantsSIRSV.size(); i++)
    {
        fileConstSIRSV << constantsSIRSV[i] << endl;
    }
    fileConstSIRSV.close();

    ofstream fileInitialValues;
    fileInitialValues.open(pathInitialValues);
    for (int i = 0; i < initialValues.size(); i++)
    {
        fileInitialValues << initialValues[i] << endl;
    }
    fileInitialValues.close();
}

void Control::UseExistingProject()
{
    string projectName = GetProjectName();
    string path = "./data/" + projectName + "/";
    string pathConstants = path + "constants.txt";
    string pathInitialValues = path + "initialValues.txt";
    string pathModelType = path + "modelType.txt";


}


void Control::Run()
{
    // cout << "Welcome to the program" << endl;
    // cout << "-----------------------" << endl;

    // cout << "Desea iniciar un nuevo proyecto? (y/n)" << endl;
    // bool newProject = GetBool("Desea iniciar un nuevo proyecto? (y/n)");
    // cout << "-----------------------" << endl;

    UseNewProject();

    // if (newProject)
    // {
    // }
    // else
    // {
    //     UseExistingProject();
    // }
}

double Control::GetDouble(string prompt)
{
    double input;

    cout << "Prompt: " << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

int Control::GetInt(string prompt)
{
    int input;

    cout << "Prompt: " << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

int Control::GetIntRange(string prompt, int min, int max)
{
    int input;

    cout << "Prompt: " << prompt << endl;
    cout << "Min: " << min << " Max: " << max << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;
        if (cin.fail() || input < min || input > max)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}

bool Control::GetBool(string prompt)
{
    string input;

    cout << "Prompt: " << prompt << endl;

    while (true)
    {
        cout << "Yes or No?" << endl
             << ">>> ";
        cin >> input;

        if (input == "yes" || input == "Yes" || input == "YES")
        {
            cin.ignore(1000, '\n');
            return true;
        }
        else if (input == "no" || input == "No" || input == "NO")
        {
            cin.ignore(1000, '\n');
            return false;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
    }
}

string Control::GetString(string prompt)
{
    string input;

    cout << "Prompt: " << prompt << endl;

    while (true)
    {
        cout << ">>> ";
        cin >> input;

        if (input == "")
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
            cout << endl;
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << endl;
    return input;
}
