#ifndef RUNGE4_H
#define RUNGE4_H

#include "models/Model.h"
#include <vector>

using namespace std;

/// @brief Clase que representa el metodo de Runge-Kutta de orden 4
class Runge4
{
    private:
        /// @brief Valores de las k1 utilizadas en el metodo
        double k11, k12, k13, k14;
        /// @brief Valores de las k2 utilizadas en el metodo
        double k21, k22, k23, k24;
        /// @brief Valores de las k3 utilizadas en el metodo
        double k31, k32, k33, k34;
        
        /// @brief Modelo de ecuaciones diferenciales a resolver
        Model *model;
        /// @brief Resultado de la ejecucion del metodo [t[n], s[n], i[n], r[n]]
        double **result;
        /// @brief Longitud del resultado length(t[n], s[n], i[n], r[n]) = n
        double length;
    public:
        Runge4();

        /// @brief Establece el modelo a resolver
        /// @param model Modelo a resolver
        void SetModel(Model *);
        /// @brief Calcula los valores de las derivadas
        /// @param t tiempo del paso actual
        /// @param dt paso de tiempo
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion removida
        /// @return Arreglo con los nuevos valores de la poblacion [s, i, r]
        double *Calc(double, double, double, double, double);
        /// @brief Ejecuta el metodo de Runge-Kutta de orden 4
        /// @param t tiempo inicial
        /// @param dt paso de tiempo
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion removida
        /// @param tmax tiempo maximo de ejecucion
        void DoMethod(vector<double>);

        /// @brief Obtiene el resultado de la ejecucion del metodo
        /// @return Arreglo con el resultado de la ejecucion del metodo [t[n], s[n], i[n], r[n]]
        double **GetResult();
        /// @brief Obtiene la longitud del resultado
        /// @return Longitud del resultado length(t[n], s[n], i[n], r[n]) = n
        double GetLength();
};

#endif
