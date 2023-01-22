#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../program.h"
#include "../images/Images.h"
#include "../../enums/enums.h"
#include "../../methods/models/Models.h"
#include "../../methods/Runge4.h"

using namespace std;

/// @brief Clase que se encarga de la interaccion con el usuario
class Control
{
    private:
        const string PATH = "./data";
        vector<string> GetFoldersName();
        void PrintFoldersName(vector<string>);
        void UseNewProject();
        void UseExistingProject();
        Model *GetModel(ModelType);

        void DoSimulation(Model *, vector<double>, string);
        void SaveData(string, vector<double>);
        vector<double> LoadData(string);
    public:
        Control();

        string GetProjectName();
        ModelType GetModelType();
        /// @brief Obtener los valores iniciales del modelo
        /// @return [0] S0, [1] I0, [2] R0, [3] T0, [4] TF, [5] Dt
        vector<double> GetInitialValues();
        vector<double> GetConstants(ModelType);

        void GenerateLatexReport(string, Model *, string);

        /// @brief Metodo que se encarga de la ejecucion del programa
        void Run();

        /// @brief Obtener un double por consola
        /// @param prompt Mensaje a mostrar
        /// @return Double introducido por el usuario
        double GetDouble(string);

        /// @brief Obtener un int por consola
        /// @param prompt Mensaje a mostrar
        /// @return Int introducido por el usuario
        int GetInt(string);

        /// @brief Obtener un int por consola entre un rango dado
        /// @param prompt Mensaje a mostrar
        /// @param min Valor minimo
        /// @param max Valor maximo
        /// @return Int introducido por el usuario entre el rango
        int GetIntRange(string, int, int);

        /// @brief Obtener un bool por consola
        /// @param prompt Mensaje a mostrar
        /// @return Bool introducido por el usuario
        bool GetBool(string);

        /// @brief Obtener un string por consola
        /// @param prompt Mensaje a mostrar
        /// @return String introducido por el usuario
        string GetString(string);
};

#endif
