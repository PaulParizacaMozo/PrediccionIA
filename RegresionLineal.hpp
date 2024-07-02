#ifndef REGRESIONLINEAL_HPP
#define REGRESIONLINEAL_HPP

#include <vector>
#include <cmath>
#include <fstream>
#include "Punto.hpp"

class RegresionLineal {
private:
    std::vector<Punto> puntos;
    double m; // Pendiente
    double b; // Intersección
    double r; // Coeficiente de correlación

    // Función para calcular la media de un vector
    double promedio(const std::vector<double>& datos) const {
        double suma = 0.0;
        for (double num : datos) {
            suma += num;
        }
        return suma / datos.size();
    }

    // Función para calcular la pendiente m de la regresión lineal por mínimos cuadrados
    double calcularPendiente(const std::vector<double>& x, const std::vector<double>& y) const {
        double x_promedio = promedio(x);
        double y_promedio = promedio(y);
        double numerador = 0.0;
        double denominador = 0.0;
        for (int i = 0; i < static_cast<int>(x.size()); ++i) {
            numerador += (x[i] - x_promedio) * (y[i] - y_promedio);
            denominador += (x[i] - x_promedio) * (x[i] - x_promedio);
        }
        return numerador / denominador;
    }

    // Función para calcular la intersección b de la regresión lineal por mínimos cuadrados
    double calcularInterseccion(const std::vector<double>& x, const std::vector<double>& y, double pendiente) const {
        return promedio(y) - pendiente * promedio(x);
    }

    // Función para calcular el coeficiente de correlación r
    double calcularCoeficienteCorrelacion(const std::vector<double>& x, const std::vector<double>& y) const {
        int n = x.size();
        double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0;
        double sum_x2 = 0.0, sum_y2 = 0.0;

        for (int i = 0; i < n; ++i) {
            sum_x += x[i];
            sum_y += y[i];
            sum_xy += x[i] * y[i];
            sum_x2 += x[i] * x[i];
            sum_y2 += y[i] * y[i];
        }

        double numerador = n * sum_xy - sum_x * sum_y;
        double denominador = std::sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));

        return numerador / denominador;
    }

public:
    RegresionLineal(const std::vector<Punto>& puntos) : puntos(puntos), m(0), b(0), r(0) {
        std::vector<double> x, y;
        for (const Punto& p : puntos) {
            x.push_back(p.X);
            y.push_back(p.Y);
        }
        m = calcularPendiente(x, y);
        b = calcularInterseccion(x, y, m);
        r = calcularCoeficienteCorrelacion(x, y);
    }

    double predecir(double x) const {
        return m * x + b;
    }

    double getPendiente() const { return m; }
    double getInterseccion() const { return b; }
    double getCoeficienteCorrelacion() const { return r; }

    void exportarDatos(const std::string& nombreArchivo) const {
        std::ofstream archivo(nombreArchivo);
        archivo << "Word count,Shares,Prediction\n";
        for (const auto& punto : puntos) {
            archivo << punto.X << "," << punto.Y << "," << predecir(punto.X) << "\n";
        }
        archivo.close();
    }
};

#endif

