#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica{
    private:
        float lado;
    public:
        Cuadrado(); //no olvidar
        Cuadrado(float);
        virtual void calcularArea();
        virtual void calcularPerimetro();
        virtual void mostrarFigura();
        float getLado();
        void setLado(float);
};

#endif
