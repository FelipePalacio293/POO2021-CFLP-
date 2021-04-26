#include "circulo.h"
#include <iostream>
using namespace std;
const int CAP = 10;
const float PI = 3.1416;

Circulo::Circulo()
{
	radio = 0;
}

Circulo::Circulo(float radio)
{
	this->radio = radio;
}

float Circulo::getRadio()
{
	return this->radio;
}

void Circulo::setRadio(float radio)
{
	this->radio = radio;
}

void Circulo::calcularAreaCirculo()
{
	float areaCirculo;
	areaCirculo = ( PI * (radio*radio) );
	cout << "El area del circulo es: "<< areaCirculo << " en metros cuadrados." << endl;
}

void Circulo::calcularPerimetroCirculo()
{
	float perimetroCirculo;
	perimetroCirculo = 2 * (PI * radio);
	cout << "El perimetro del circulo es: "<< perimetroCirculo << " en metros." << endl;
}








