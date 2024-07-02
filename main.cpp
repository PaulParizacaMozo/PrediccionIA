#include <iostream>
#include <vector>
#include <string>
#include "Punto.hpp"
#include "LectorCSV.hpp"
#include "RegresionLineal.hpp"

int main() {
    std::string nombreArchivo = "articulos_ml.csv";
    LectorCSV lectorCSV(nombreArchivo);
    std::vector<Punto> datos = lectorCSV.leerCSV();

    if (datos.empty()) {
        std::cerr << "No se pudieron leer datos del archivo." << std::endl;
        return 1;
    }

    RegresionLineal regresionLineal(datos);

    double nuevaX = 2000;
    double prediccionShares = regresionLineal.predecir(nuevaX);
    std::cout << "Para Word count = " << nuevaX << ", la predicción de # Shares es: " << prediccionShares << std::endl;

    std::cout << "Pendiente (m): " << regresionLineal.getPendiente() << std::endl;
    std::cout << "Intersección (b): " << regresionLineal.getInterseccion() << std::endl;
    std::cout << "Coeficiente de correlación (r): " << regresionLineal.getCoeficienteCorrelacion() << std::endl;

    // Exportar datos a un archivo .txt
    regresionLineal.exportarDatos("regresion_lineal.txt");

    return 0;
}

