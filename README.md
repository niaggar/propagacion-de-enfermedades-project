# Proyecto final
#### Física Computacional

> **Nombre:** Propagación de enfermedades
> **Descripción:** Simulación de la propagación de enfermedades en una población

## Integrantes
- [x] 1. Nicolas Aguilera Garcia
- [x] 2. Andreas Felipe Valencia

## Descripción
Proyecto que busca simular la propagación de enfermedades en una población, utilizando una solución numérica a las ecuaciones diferenciales dadas por el modelo SIR, SIRS y SIRS-VAC.

## Utilización
El proyecto cuenta con una estructura de tres carpetas. 

> - **prop-enfermedades-app**: Contiene el código de la aplicación de consola que permite interactuar con el usuario y ejecutar las simulaciones. Esta aplicación está escrita en C++.
> - **prop-enfermedades-article**: Contiene el Código LaTeX del artículo que describe el proyecto.
> - **references**: Contiene los archivos de referencia que se utilizaron para el desarrollo del proyecto.

Para ejecutar el proyecto, se debe clonar el repositorio y ejecutar el archivo `main.cpp` que se encuentra en la carpeta `prop-enfermedades-app`.

Para esto se debe tener instalado el compilador de `C++`, `gnuplot` y `ffmpeg` (programa de consola que permite generar Gif de mejor calidad que los generados mediante `convert`).

Recomendamos tener linux y seguir los siguientes pasos:

1. Clonar el repositorio
2. Tener instalado `gnuplot` y `ffmpeg`
3. Navegar a la carpeta `prop-enfermedades-app`
4. Ejecutar el comando `make` para compilar el proyecto
5. Ejecutar el comando `make run` para ejecutar el proyecto
6. Utilizar el programa de consola para interactuar con el usuario y ejecutar las simulaciones
7. Los datos de las simulaciones se guardan en la carpeta `data` dentro de la carpeta `prop-enfermedades-app`

