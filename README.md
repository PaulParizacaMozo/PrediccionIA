### Predicción IA

Este proyecto implementa un modelo de regresión lineal para predecir el número de compartidos (`Shares`) basado en el recuento de palabras (`Word count`) de artículos. El proyecto consta de tres partes principales: lectura de datos desde un archivo CSV, cálculo de la regresión lineal y visualización de los resultados.

#### Estructura del Proyecto

- **Punto.hpp**: Define la clase `Punto`, que representa un punto en el plano 2D con coordenadas `X` y `Y`.
- **LectorCSV.hpp**: Define la clase `LectorCSV`, que se encarga de leer los datos desde un archivo CSV y convertirlos en objetos `Punto`.
- **RegresionLineal.hpp**: Define la clase `RegresionLineal`, que calcula la regresión lineal usando los datos leídos y exporta los resultados a un archivo `.txt`.
- **main.cpp**: Contiene el punto de entrada del programa en C++. Lee los datos, calcula la regresión lineal y exporta los resultados.
- **graficar.py**: Script en Python que lee el archivo `.txt` exportado y genera una gráfica de la regresión lineal con los puntos diferenciados por colores.

#### Requisitos

- g++ (compilador de C++)
- Python 3.x
- Bibliotecas de Python: `matplotlib`, `pandas`

#### Compilación y Ejecución

1. **Compilar y Ejecutar el Programa en C++**

```sh
g++ main.cpp -o eject -Wall -pedantic && ./eject
```

2. **Ejecutar el Script de Python para Generar la Gráfica**

```sh
python graficar.py
```

#### Explicación de los Resultados

1. **Lectura del CSV**: El programa en C++ lee los datos del archivo `articulos_ml.csv` y los convierte en objetos `Punto`.
2. **Cálculo de la Regresión Lineal**: Se calculan los coeficientes de la regresión lineal: pendiente (`m`), intersección (`b`) y coeficiente de correlación (`r`). También se realiza una predicción para un valor específico de `Word count`.
3. **Exportación de Datos**: Los datos y las predicciones se guardan en un archivo `regresion_lineal.txt`.
4. **Generación de la Gráfica**: El script de Python lee el archivo exportado y genera una gráfica de dispersión con los puntos diferenciados por colores:
    - Puntos con `Word count > 1808` en rojo.
    - Puntos con `Word count <= 1808` en azul.
    - La línea de regresión lineal en verde.

La gráfica final muestra la relación entre `Word count` y `Shares`, destacando los puntos y la línea de regresión, lo que permite visualizar cómo varían los compartidos en función del recuento de palabras.

#### Archivos del Proyecto

- `Punto.hpp`: Define la clase `Punto`.
- `LectorCSV.hpp`: Define la clase `LectorCSV`.
- `RegresionLineal.hpp`: Define la clase `RegresionLineal`.
- `main.cpp`: Código principal del programa en C++.
- `graficar.py`: Script en Python para generar la gráfica.
- `articulos_ml.csv`: Archivo CSV de ejemplo con datos de entrada.
- `regresion_lineal.txt`: Archivo generado con los resultados de la regresión lineal.
