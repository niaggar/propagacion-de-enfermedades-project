#include "Control.h"

void Control::UseNewProject()
{
    string projectName = GetString("Enter project name");
    string path = PATH + "/" + projectName;
    mkdir(path.c_str(), 0777);

    cout << "Se ha creado el proyecto: " << projectName << endl;

    vector<double> initialValues = GetInitialValues();
    vector<ModelType> modelsUsed;

    bool createCour = GetBool("Do you want to create a contour plot?");
    bool createModel = GetBool("Do you want to create a model?");
    bool normalize = GetBool("Do you want to normalize the data (by default they are not normalized)?");

    double N = initialValues[0] + initialValues[1] + initialValues[2];
    if (normalize)
        for (int i = 0; i < 3; i++)
            initialValues[i] /= N;

    if (createCour)
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "Creating contour plot" << endl;
        Contour(path, initialValues);
        cout << "The result of the contour plot has been saved in: " << path << endl;
        cout << "------------------------------------------------------------" << endl << endl;
    }

    if (createModel)
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "Creating model" << endl << endl;
        // bool useModel = GetBool("Do you want to use a specific model (all models are used by default)?");
        bool useModel = true;

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
            GenerateLatexReport(path, model, projectName, N);

            cout << "The result of the model has been saved " << model->modelName << " in: " << path << endl;
        }
        else
        {
            cout << "All models will be used" << endl;

            for (int i = 1; i <= 3; i++)
            {
                ModelType modelType = static_cast<ModelType>(i);
                Model *model = GetModel(modelType);
                modelsUsed.push_back(modelType);

                cout << "inciando con modelo: " << model->modelName << endl;

                vector<double> constants = GetConstants(model->modelType);
                model->SetParameters(constants);

                SaveData(path + "/const-" + model->modelName + ".dat", constants);
                SaveData(path + "/init-" + model->modelName + ".dat", initialValues);
                DoSimulation(model, initialValues, path);
                GenerateLatexReport(path, model, projectName, N);

                cout << "The result of the model has been saved " << model->modelName << " in: " << path << endl;
            }
        }

        cout << "------------------------------------------------------------" << endl << endl;
    }
}

void Control::UseExistingProject() // TODO: terminar
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
    string pathPhase = path + "/phase-" + model->modelName + ".dat";
    string pathPhaseRes = path + "/phase-" + model->modelName + ".png";

    Runge4 *runge4 = new Runge4();
    runge4->SetModel(model);
    runge4->DoMethod(initialValues);

    double **res = runge4->GetResult();
    int size = runge4->GetLength();

    WriteData(pathResult, res, size);

    double population = initialValues[0] + initialValues[1] + initialValues[2];
    double startTime = initialValues[3];
    double maxTime = initialValues[4];

    Phase(path, model);

    Images *images = new Images();
    images->GenerateBasicPlot(pathResult, pathGraph);
    images->GererateBasicGif(model, path, size, startTime, maxTime, population);
    images->GeneratePhasePlot(pathPhase, pathPhaseRes);
    images->GereratePhaseGif(model, path, size, startTime, maxTime, population);

    delete runge4;
    delete images;
}

Model *Control::GetModel(ModelType modelType)
{
    Model *model = new SirModel();
    switch (modelType)
    {
        case ModelType::SIR:
            model = new SirModel();
            return model;

        case ModelType::SIRS:
            model = new SirsModel();
            return model;

        case ModelType::SIRSV:
            model = new SirsVacModel();
            return model;
    }

    return model;
}
