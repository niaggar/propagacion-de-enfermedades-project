#include "Control.h"

void Control::UseNewProject()
{
    string projectName = GetString("Enter project name");
    string path = PATH + "/" + projectName;
    mkdir(path.c_str(), 0777);

    cout << "Se ha creado el proyecto: " << projectName << endl;

    vector<double> initialValues = GetInitialValues();
    vector<ModelType> modelsUsed;

    bool useModel = GetBool("Do you want to use a specific model (all models are used by default)?");
    bool normalize = GetBool("Do you want to normalize the data (by default they are not normalized)?");

    double N = initialValues[0] + initialValues[1] + initialValues[2];
    if (normalize)
        for (int i = 0; i < 3; i++)
            initialValues[i] /= N;

    if (useModel)
    {
        ModelType modelType = GetModelType();
        vector<double> constants = GetConstants(modelType);

        Model *model = GetModel(modelType);
        modelsUsed.push_back(modelType);

        model->SetParameters(constants);
        SaveData(path + "/const-" + model->modelName + ".dat", constants);
        SaveData(path + "/init-" + model->modelName + ".dat", initialValues);
        DoSimulation(model, initialValues, path);
        Phase(path, model);
        GenerateLatexReport(path, model, projectName);

        cout << "The result of the model has been saved " << model->modelName << " in: " << path << endl;
    }
    else
    {
        cout << "All models will be used" << endl;

        Model *model;
        for (int i = 0; i < 3; i++)
        {
            ModelType modelType = (ModelType)i;
            model = GetModel(modelType);
            modelsUsed.push_back(modelType);

            vector<double> constants = GetConstants(model->modelType);
            model->SetParameters(constants);

            SaveData(path + "/const-" + model->modelName + ".dat", constants);
            SaveData(path + "/init-" + model->modelName + ".dat", initialValues);
            DoSimulation(model, initialValues, path);
            Phase(path, model);
            GenerateLatexReport(path, model, projectName);

            cout << "The result of the model has been saved " << model->modelName << " in: " << path << endl;
        }
    }
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

void Control::DoSimulation(Model *model, vector<double> initialValues, string path)
{
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


Model *Control::GetModel(ModelType modelType)
{
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

    return model;
}
