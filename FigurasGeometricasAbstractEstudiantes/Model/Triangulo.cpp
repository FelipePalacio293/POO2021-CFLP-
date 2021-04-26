#include "triangulo.h"

//CONSTRUCTORES TRIANGULO

Triangulo::Triangulo() {}

Triangulo::Triangulo(float base, float altura)
{

    this->base = base;
    this->altura = altura;
}

//METODOS TRIANGULO

void Triangulo::calcularArea()
{
    this->area = (base * altura) / 2;
}

void Triangulo::calcularPerimetro()
{
    float temp;
    temp = base / 2;
    this->perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
}

void Triangulo::mostrarFigura(){
    cout << "La base es: " << this->base << endl;
    cout << "La altura es: " << this->altura << endl;
    if(this->area == 0){
        this->calcularArea();
    }
    if(this->perimetro == 0){
        this->calcularPerimetro();
    }
    cout << "El area del triangulos es " << this->area << endl;
    cout << "El perimetro del perimetro es " << this->perimetro << endl;
}