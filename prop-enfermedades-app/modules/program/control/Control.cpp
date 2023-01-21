#include "Control.h"

Control::Control() {}


void Control::UseNewProject()
{
    string projectName = GetString("Introduzca el nombre del proyecto");
    string path = PATH + "/" + projectName;
    mkdir(path.c_str(), 0777);

    cout << "Se ha creado el proyecto: " << projectName << endl;

    vector<double> initialValues = GetInitialValues();

    bool useModel = GetBool("¿Desea usar un modelo en concreto? (por defecto se usran todos los modelos)");
    bool normalize = GetBool("¿Desea normalizar los datos? (por defecto no se normalizan)");

    double N = initialValues[0] + initialValues[1] + initialValues[2];
    if (normalize)
        for (int i = 0; i < 3; i++)
            initialValues[i] /= N;

    if (useModel)
    {
        ModelType modelType = GetModelType();
        vector<double> constants = GetConstants(modelType);

        Model *model;
        switch (modelType)
        {
            case SIR:
                model = new SirModel();
                break;
            case SIRS:
                model = new SirsModel();
                break;
            case SIRSV:
                model = new SirsVacModel();
                break;
        }

        SaveData(path + "/const-" + model->modelName + ".dat", constants);
        DoSimulation(model, initialValues, constants, path);
        Phase(path, modelType);

        cout << "Se ha guardado el resultado del modelo " << model->modelName << " en: " << path << endl;
    }
    else
    {
        cout << "Se usaran todos los modelos" << endl;

        Model *model = new Model[3];
        SirModel *sirModel = new SirModel();
        SirsModel *sirsModel = new SirsModel();
        SirsVacModel *sirsvModel = new SirsVacModel();

        model[0] = *sirModel;
        model[1] = *sirsModel;
        model[2] = *sirsvModel;

        for (int i = 0; i < 3; i++)
        {
            vector<double> constants = GetConstants(model[i].modelType);
            SaveData(path + "/const-" + model[i].modelName + ".dat", constants);
            DoSimulation(&model[i], initialValues, constants, path);

            cout << "Se ha guardado el resultado del modelo " << model[i].modelName << " en: " << path << endl;
        }
    }
}

void Control::DoSimulation(Model *model, vector<double> initialValues, vector<double> constants, string path)
{
    model->SetParameters(constants);

    string pathResult = path + "/result-" + model->modelName + ".dat";
    string pathGraph = path + "/graph-" + model->modelName + ".png";

    Runge4 *runge4 = new Runge4();
    runge4->SetModel(model);
    runge4->DoMethod(initialValues);

    double **res = runge4->GetResult();
    int size = runge4->GetLength();
    
    WriteData(pathResult, res, size);
    Images *images = new Images();
    images->GenerateBasicPlot(pathResult, pathGraph);

    delete runge4;
    delete images;
}


void Control::SaveData(string path, vector<double> data)
{
    ofstream file;
    file.open(path);
    for (int i = 0; i < data.size(); i++)
    {
        file << data[i] << endl;
    }
    file.close();
}

vector<double> Control::LoadData(string path)
{
    vector<double> data;
    ifstream file;
    file.open(path);
    string line;
    while (getline(file, line))
    {
        data.push_back(stod(line));
    }
    file.close();
    return data;
}


void Control::UseExistingProject()
{
    // string projectName = GetProjectName();
    // string path = "./data/" + projectName + "/";
    // string pathConstants = path + "constants.txt";
    // string pathInitialValues = path + "initialValues.txt";
    // string pathModelType = path + "modelType.txt";

    // vector<double> constants = LoadData(pathConstants);
    // vector<double> initialValues = LoadData(pathInitialValues);
    // ModelType modelType = (ModelType)GetInt(pathModelType);


}


void Control::Run()
{
    cout << "Welcome to the program" << endl;
    cout << "-----------------------" << endl;
    bool newProject = GetBool("Desea iniciar un nuevo proyecto? (y/n)");
    cout << "-----------------------" << endl;


    if (newProject)
    {
        UseNewProject();
    }
    else
    {
        UseExistingProject();
    }
}

double Control::GetDouble(string prompt)
{
    double input;

    cout << prompt << endl;

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

    cout << prompt << endl;

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

    cout << prompt << endl;
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

    cout << prompt << endl;

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

    cout << prompt << endl;

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
