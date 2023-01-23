#include "Control.h"

void Control::SaveData(string path, vector<double> data)
{
    ofstream file;
    file.open(path);
    for (int i = 0; i < (int)data.size(); i++)
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

ModelType Control::GetModelType()
{
    cout << "------ Get model type ------" << endl;
    cout << "\t"
         << "1. SIR" << endl;
    cout << "\t"
         << "2. SIRS" << endl;
    cout << "\t"
         << "3. SIRSV" << endl;
    int modelType = GetIntRange("Enter the type of model", 1, 3);
    cout << "-----------------------" << endl;
    cout << endl;

    return static_cast<ModelType>(modelType);
}

vector<double> Control::GetConstants(ModelType modelType)
{
    vector<string> *constantsName;
    if (modelType == ModelType::SIR)
    {
        constantsName = new vector<string>{"b", "k"};
    }
    else if (modelType == ModelType::SIRS)
    {
        constantsName = new vector<string>{"m", "b", "v"};
    }
    else if (modelType == ModelType::SIRSV)
    {
        constantsName = new vector<string>{"m", "b", "v", "g1", "g2"};
    }

    cout << "------ Get constants values ------" << endl;
    vector<double> constants;
    for (int i = 0; i < (int)constantsName->size(); i++)
    {
        constants.push_back(GetDouble("Enter the value of: " + constantsName->at(i)));
    }
    cout << "-----------------------" << endl;
    cout << endl;

    return constants;
}

vector<double> Control::GetInitialValues()
{
    vector<double> initialValues;

    cout << "------ Get initial values ------" << endl;
    initialValues.push_back(GetDouble("Enter the value of the SUCEPTIBLE population"));
    initialValues.push_back(GetDouble("Enter the value of the INFECTED population"));
    initialValues.push_back(GetDouble("Enter the value of the REMOVED population"));
    cout << endl;
    initialValues.push_back(GetDouble("Enter the value of the INITIAL time"));
    initialValues.push_back(GetDouble("Enter the FINAL time value"));
    initialValues.push_back(GetDouble("Enter the STEP value"));
    cout << "-----------------------" << endl;
    cout << endl;

    return initialValues;
}
