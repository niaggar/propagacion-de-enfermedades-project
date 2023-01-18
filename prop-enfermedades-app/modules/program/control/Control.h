#include <iostream>
#include <string>

using namespace std;

/// @brief Clase que se encarga de la interaccion con el usuario
class Control
{
private:
public:
    Control();

    /// @brief Metodo que se encarga de la ejecucion del programa
    void run();

    /// @brief Obtener un double por consola
    /// @param prompt Mensaje a mostrar
    /// @return Double introducido por el usuario
    double getDouble(string);

    /// @brief Obtener un int por consola entre un rango dado
    /// @param prompt Mensaje a mostrar
    /// @param min Valor minimo
    /// @param max Valor maximo
    /// @return Int introducido por el usuario entre el rango
    int getIntRange(string, int, int);

    /// @brief Obtener un bool por consola
    /// @param prompt Mensaje a mostrar
    /// @return Bool introducido por el usuario
    bool getBool(string);

    /// @brief Obtener un string por consola
    /// @param prompt Mensaje a mostrar
    /// @return String introducido por el usuario
    string getString(string);
};
