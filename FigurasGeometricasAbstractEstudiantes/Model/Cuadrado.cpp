#include "Cuadrado.h"


Cuadrado::Cuadrado() {}

Cuadrado::Cuadrado(float lado)
{
    this->lado = lado;
}

void Cuadrado::calcularArea()
{
    this->area = this->lado * this->lado;
}

void Cuadrado::calcularPerimetro()
{
    this->perimetro = 4 * this->lado;
}

void Cuadrado::mostrarFigura()
{
    cout << "El lado es: " << lado << endl;
    if(this->area == 0){
        calcularArea();
    }
    if(this->perimetro == 0){
        calcularPerimetro();
    }
    cout << "El area del cuadrado es " << this->area << endl;
    cout << "El perimetro del cuadrado es " << this->perimetro << endl;
}

float Cuadrado::getLado()
{
    return this->lado;
}

void Cuadrado::setLado(float ancho)
{
    this->lado = lado;
}