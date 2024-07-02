#ifndef LECTORCSV_HPP
#define LECTORCSV_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Punto.hpp"

class LectorCSV {
private:
    std::string nombreArchivo;

public:
    LectorCSV(const std::string& nombreArchivo) : nombreArchivo(nombreArchivo) {}

    std::vector<Punto> leerCSV() {
        std::vector<Punto> datos;
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
            return datos;
        }

        std::string linea;
        std::getline(archivo, linea);

        while (std::getline(archivo, linea)) {
            Punto punto;
            int indiceColumna = 1;
            bool enComillas = false;
            std::string texto = "";

            for (size_t i = 0; i < linea.size(); ++i) {
                if (linea[i] == '"' && !enComillas) {
                    enComillas = true;
                    continue;
                }
                if (linea[i] == '"' && enComillas) {
                    enComillas = false;
                    continue;
                }
                if (!enComillas && linea[i] == ',') {
                    if (indiceColumna == 3) {
                        punto.X = std::stod(texto);
                    } else if (indiceColumna == 8) {
                        punto.Y = std::stod(texto);
                    }
                    indiceColumna++;
                    texto = "";
                } else {
                    texto += linea[i];
                }
            }

            if (!texto.empty()) {
                if (indiceColumna == 3) {
                    punto.X = std::stod(texto);
                } else if (indiceColumna == 8) {
                    punto.Y = std::stod(texto);
                }
            }

            // Filtrado de  datos
            if (punto.X <= 3500 && punto.Y <= 80000) {
                datos.push_back(punto);
            }
        }

        archivo.close();
        return datos;
    }
};

#endif

