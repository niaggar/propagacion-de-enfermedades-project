#ifndef SIRSMODEL_H
#define SIRSMODEL_H

#include "Model.h"

/// @brief Clase que representa el modelo SIRS -- Modelo secundario del trabajo
class SirsModel : public Model
{
    private:
        /// @brief mu, tasa de nacimiento natural de la poblacion
        double m;
        /// @brief beta, capacidad de infeccion de la enfermedad
        double b;
        /// @brief v, proporcio de removidos que se transforman en susceptibles
        double v;
    public:
        SirsModel();

        /// @brief Establece los parametros del modelo
        /// @param m mu, tasa de nacimiento natural de la poblacion
        /// @param b beta, capacidad de infeccion de la enfermedad
        /// @param v v, proporcion de removidos que se transforman en susceptibles
        void SetParameters(double m, double b, double v);

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
        /// @brief Ecuacion diferencial que representa la poblacion removida
        /// @param t tiempo actual
        /// @param s poblacion susceptible
        /// @param i poblacion infectada
        /// @param r poblacion recuperada
        /// @return Tasa de cambio de la poblacion removida
        double Removed(double t, double s, double i, double r) override;

        /// @brief Obtiene el valor de: tasa de nacimiento natural de la poblacion
        double GetM();
        /// @brief Obtiene el valor de: capacidad de infeccion de la enfermedad
        double GetB();
        /// @brief Obtiene el valor de: proporcio de removidos que se transforman en susceptibles
        double GetV();
};

#endif
