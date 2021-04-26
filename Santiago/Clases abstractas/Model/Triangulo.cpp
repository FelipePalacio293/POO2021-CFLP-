#include "triangulo.h"

//CONSTRUCTORES TRIANGULO

Triangulo::Triangulo()
{
}

Triangulo::Triangulo(float base, float altura)
{
    this->base = base;
    this->altura = altura;
}

//METODOS TRIANGULO

void Triangulo::calcularArea()
{
    float area;
    area = (base * altura) / 2;
    std::cout << "El area del Triangulo es: " << area << std::endl;
}

void Triangulo::calcularPerimetro()
{
    float perimetro, temp;
    temp = base / 2;
    perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
    std::cout << "El perimetro del Triangulo es: " << perimetro << std::endl;
}

void Triangulo::mostrarFigura()
{
    cout << "La base: " << base << " -- " << "La altura : " << altura << endl;
    if(this->area == 0)
    {
        this->calcularArea();
    }
    if(this->perimetro == 0)
    {
        this->calcularPerimetro();
    }
    cout << "El area del triangulo es: " << this->area << endl;
    cout << "El perimetro del triangulo es: " << this->perimetro << endl;

    FiguraGeometrica::mostrarFigura();
}

float Triangulo::getBase()
{
    return this->base;
}

float Triangulo::getAltura()
{
    return this->altura;
}

void Triangulo::setBase(float base)
{
    this->base = base;
}

void Triangulo::setAltura(float altura)
{
    this->altura = altura;
}