#ifndef SIRSVACMODEL_H
#define SIRSVACMODEL_H

#include <functional>
#include "Model.h"

using namespace std;

/// @brief Clase que representa el modelo SIRS con vacunacion -- Modelo secundario del trabajo
class SirsVacModel : public Model
{
private:
    /// @brief mu, tasa de nacimiento natural de la poblacion
    double m;
    /// @brief k, capacidad de soporte de la poblacion suceptible
    double K;
    /// @brief beta, capacidad de infeccion de la enfermedad
    double b;
    /// @brief delta, tasa de muerte natural de la poblacion
    double d;
    /// @brief proporcio de la poblacion suceptible que se vacuna
    function<double(double)> u;
    /// @brief v, proporcio de removidos que se transforman en susceptibles
    double v;
    /// @brief epsilon, tasa de muerte por la enfermedad
    double e;
    /// @brief gama, proporcion de infectados que se transforman en removidos
    double g;

public:
    SirsVacModel();

    /// @brief Establece los parametros del modelo
    /// @param m mu, tasa de nacimiento natural de la poblacion
    /// @param K k, capacidad de soporte de la poblacion suceptible
    /// @param b beta, capacidad de infeccion de la enfermedad
    /// @param d delta, tasa de muerte natural de la poblacion
    /// @param v v, proporcio de removidos que se transforman en susceptibles
    /// @param e epsilon, tasa de muerte por la enfermedad
    /// @param g gama, proporcion de infectados que se transforman en removidos
    /// @param u proporcio de la poblacion suceptible que se vacuna
    void SetParameters(double m, double K, double b, double d, double v, double e, double g, function<double(double)> u);

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
    /// @brief Obtiene el valor de: capacidad de soporte de la poblacion suceptible
    double GetK();
    /// @brief Obtiene el valor de: capacidad de infeccion de la enfermedad
    double GetB();
    /// @brief Obtiene el valor de: tasa de muerte natural de la poblacion
    double GetD();
    /// @brief Obtiene el valor de: proporcio de removidos que se transforman en susceptibles
    double GetV();
    /// @brief Obtiene el valor de: tasa de muerte por la enfermedad
    double GetE();
    /// @brief Obtiene el valor de: proporcion de infectados que se transforman en removidos
    double GetG();
};

#endif