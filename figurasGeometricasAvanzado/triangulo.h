#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figuraGeometrica.h"

class Triangulo : public FiguraGeometrica
{
	private:
		float base, altura;
	public:
		Triangulo();
		Triangulo(float, float);
		void calcularAreaTriangulo();
		void calcularPerimetroTriangulo();
		float getBase();
		void setBase(float);
		float getAltura();
		void setAltura(float);
};

#endif