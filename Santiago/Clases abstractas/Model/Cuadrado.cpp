#include "Cuadrado.h"

//CONSTRUCTORES CUADRADO

Cuadrado::Cuadrado()
{
}

Cuadrado::Cuadrado(float lado)
{
    this->lado = lado;
}

//METODOS CUADRADO

void Cuadrado::calcularArea()
{
    this->area = (this->lado * 2);
}

void Cuadrado::calcularPerimetro()
{
    this->perimetro = (this->lado * 4);
}

void Cuadrado::mostrarFigura()
{
    cout << "El lado: " << lado << endl;
    if(this->area == 0) // Si no ha calculado el area
    {
        this->calcularArea();
    }
    if(this->perimetro == 0)
    {
        this->calcularPerimetro();
    }
    cout << "El area del cuadrado es: " << this->area << endl;
    cout << "El perimetro del rectangulo es: " << this->perimetro << endl;

    FiguraGeometrica::mostrarFigura();
}

float Cuadrado::getLado()
{
    return this->lado;
}

void Cuadrado::setLado(float lado)
{
    this->lado = lado;
}