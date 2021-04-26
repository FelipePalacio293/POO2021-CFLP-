#include "triangulo.h"


const int CAP = 10;

Triangulo::Triangulo()
{
	base = 0;
	altura = 0;
}

Triangulo::Triangulo(float, float){
	this->base = base;
	this->altura = altura;
}

float Triangulo::getBase()
{
	return this->base;
}

void Triangulo::setBase(float base)
{
	this->base = base;
}
 
float Triangulo::getAltura()
{
	return this->altura;
}

void Triangulo::setAltura(float altura)
{
	this->altura = altura;
}

void Triangulo::calcularAreaTriangulo()
{
	float areaTriangulo;
	areaTriangulo = ((base * altura) / 2);
	cout << "El area del triangulo equilatero es: " << areaTriangulo << " en metros cuadrados.\n";
}

void Triangulo::calcularPerimetroTriangulo()
{
	float perimetroTriangulo;
	perimetroTriangulo = (base * 3);
	cout << "El perimetro del triangulo equilatero es: " << perimetroTriangulo << " en metros.\n";
}

