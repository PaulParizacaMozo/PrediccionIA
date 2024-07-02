#ifndef PUNTO_HPP
#define PUNTO_HPP

class Punto {
public:
    double X;
    double Y;

    Punto() : X(0), Y(0) {}
    Punto(double x, double y) : X(x), Y(y) {}

    void setPunto(double x, double y) {
        X = x;
        Y = y;
    }
};

#endif
