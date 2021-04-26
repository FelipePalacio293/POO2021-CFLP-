#include "rectangulo.h"
#include <iostream>
using namespace std;
const int CAP = 10;

Rectangulo::Rectangulo()
{
	ancho = 0;
	largo = 0;
}

Rectangulo::Rectangulo(float ancho, float largo)
{
	this->ancho = ancho;
	this->largo = largo;
}

float Rectangulo::getAncho()
{
	return this->ancho;
}

void Rectangulo::setAncho(float ancho)
{
	this->ancho = ancho;
}

float Rectangulo::getLargo()
{
	return this->largo;
}

void Rectangulo::setLargo(float largo)
{
	this->largo = largo;
}

void Rectangulo::calcularAreaRectangulo()
{
	float areaRectangulo;
	areaRectangulo = ( ancho * largo );
	cout << "El area del rectangulo es: " << areaRectangulo << " en metros cuadrados." << endl;
}

void Rectangulo::calcularPerimetroRectangulo()
{
	float perimetroRectangulo;
	perimetroRectangulo = (2 * ancho) + (2 * largo);
	cout << "El perimetro del rectangulo es: " << perimetroRectangulo << " en metros." << endl;
}

