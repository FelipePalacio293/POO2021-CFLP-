#include "Rectangulo.h"

//CONSTRUCTORES RECTANGULO

Rectangulo::Rectangulo() {}

Rectangulo::Rectangulo(float ancho, float largo)
{
    this->ancho = ancho;
    this->largo = largo;
}

//METODOS RECTANGULO

void Rectangulo::calcularArea()
{
    this->area = this->largo * this->ancho;
}

void Rectangulo::calcularPerimetro()
{
    this->perimetro = (2 * this->largo) + (2 * this->ancho);
}

void Rectangulo::mostrarFigura()
{
    cout << "La base es: " << this->ancho << endl;
    cout << "La altura es: " << this->largo << endl;
    if(this->area == 0){
        calcularArea();
    }
    if(this->perimetro == 0){
        calcularPerimetro();
    }
    cout << "El area del rectangulo es " << this->area << endl;
    cout << "El perimetro del rectangulo es " << this->perimetro << endl;
}

float Rectangulo::getAncho()
{
    return this->ancho;
}

float Rectangulo::getLargo()
{
    return this->largo;
}

void Rectangulo::setAncho(float ancho)
{
    this->ancho = ancho;
}

void Rectangulo::setLargo(float largo)
{
    this->largo = largo;
}
