#include "Control.h"

ModelType Control::GetModelType()
{
    cout << "------ Get model type ------" << endl;
    cout << "\t"
         << "1. SIR" << endl;
    cout << "\t"
         << "2. SIRS" << endl;
    cout << "\t"
         << "3. SIRSV" << endl;
    int modelType = GetIntRange("Introduce el tipo de modelo", 1, 3);
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
    for (int i = 0; i < constantsName->size(); i++)
    {
        constants.push_back(GetDouble("Introduce el valor de: " + constantsName->at(i)));
    }
    cout << "-----------------------" << endl;
    cout << endl;

    return constants;
}

vector<double> Control::GetInitialValues()
{
    vector<double> initialValues;

    cout << "------ Get initial values ------" << endl;
    initialValues.push_back(GetDouble("Introduce el valor de la poblacion SUCEPTIBLE"));
    initialValues.push_back(GetDouble("Introduce el valor de la poblacion INFECTADA"));
    initialValues.push_back(GetDouble("Introduce el valor de la poblacion REMOVIDA"));
    cout << endl;
    initialValues.push_back(GetDouble("Introduce el valor del tiempo INICIAL"));
    initialValues.push_back(GetDouble("Introduce el valor del tiempo FINAL"));
    initialValues.push_back(GetDouble("Introduce el valor del PASO"));
    cout << "-----------------------" << endl;
    cout << endl;

    return initialValues;
}
