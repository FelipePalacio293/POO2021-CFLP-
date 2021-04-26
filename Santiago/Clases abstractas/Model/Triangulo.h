//#ifndef TRINANGULO_H
// Guardas
//#define TRIANGULO_H

//CLASE TRIANGULO

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "FiguraGeometrica.h"

using std::cin;
using std::cout;
using std::endl;

class Triangulo : public FiguraGeometrica
{
private:
    float base, altura;

public:
    Triangulo();
    Triangulo(float, float);
    void mostrarFigura() const;
    virtual void calcularArea();
    virtual void calcularPerimetro();
    virtual void mostrarFigura();
    float getBase();
    float getAltura();
    void setBase(float);
    void setAltura(float);
};

//#endif /* !TRIANGULO_H */