//CLASE CUADRADO
#include <iostream>
#include <cstdlib>

#include "FiguraGeometrica.h"

using std::cin;
using std::cout;
using std::endl;

class Cuadrado : public FiguraGeometrica
{
    private:
        float lado;
    
    public:
        Cuadrado();
        Cuadrado(float);
        void mostrarFigura() const;
        virtual void calcularArea();
        virtual void calcularPerimetro();
        virtual void mostrarFigura();
        float getLado();
        void setLado(float);
};