#include "Circulo.h"

//Inicializa la variable PI que es estática y constante
const float Circulo::PI = 3.1416;

//CONSTRUCTORES CIRCULO
Circulo::Circulo()
{
}

Circulo::Circulo(float radio)
{
    this->radio = radio;
}

//METODOS CIRCULO

void Circulo::calcularArea()
{
    this->area = PI * (this->radio * this->radio);
}

void Circulo::calcularPerimetro()
{
    this->perimetro = (2 * PI) * this->radio;
}

void Circulo::mostrarFigura()
{
    cout << "El radio es: " << this->radio << endl;
    if(this->area == 0){
        this->calcularArea();
    }
    if(this->perimetro == 0){
        this->calcularPerimetro();
    }
    cout << "El area del circulo es " << this->area << endl;
    cout << "El circulo del perimetro es " << this->perimetro << endl;
}

float Circulo::getRadio() const
{

    return this->radio;
}

void Circulo::setRadio(float radio)
{

    this->radio = radio;
}