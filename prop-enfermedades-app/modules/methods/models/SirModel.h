#ifndef SIRMODEL_H
#define SIRMODEL_H

#include "Model.h"

/// @brief Clase que representa el modelo SIR -- Modelo principal del trabajo
class SirModel : public Model
{
    private:
        /// @brief contactos que pueden producir infeccion
        double b;
        /// @brief fraccion de infectados que se recupera
        double k;

        
    public:
        SirModel();

        /// @brief Establece los parametros del modelo
        /// @param b valor: contactos que pueden producir infeccion
        /// @param k valor: fraccion de infectados que se recupera
        void SetParameters(vector<double>) override;

        /// @brief Ecuacion diferencial que representa la poblacion susceptible
        /// @param t tiempo actual
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion recuperada
        /// @return Tasa de cambio de la poblacion susceptible
        double Susceptible(double t, double s, double i, double r) override;
        /// @brief Ecuacion diferencial que representa la poblacion infectada
        /// @param t tiempo actual
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion recuperada
        /// @return Tasa de cambio de la poblacion infectada
        double Infected(double t, double s, double i, double r) override;
        /// @brief Ecuacion diferencial que representa la poblacion recuperada
        /// @param t tiempo actual
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion recuperada
        /// @return Tasa de cambio de la poblacion recuperada
        double Removed(double t, double s, double i, double r) override;

        /// @brief Obtiene el valor de: contactos que pueden producir infeccion
        double GetB();
        /// @brief Obtiene el valor de: fraccion de infectados que se recupera
        double GetK();
};

#endif
