#ifndef ENUMS_H
#define ENUMS_H

/// @brief Tipos de poblacion que se pueden tener en el modelo
enum PopulationType {
    /// @brief Poblacion susceptible
    Susceptible = 1,
    /// @brief Poblacion infectada
    Infected = 2,
    /// @brief Poblacion recuperada
    Removed = 3
};

enum ModelType {
    /// @brief Modelo SIR
    SIR = 1,
    /// @brief Modelo SIRS
    SIRS = 2,
    /// @brief Modelo SIRSV
    SIRSV = 3,
};

#endif
