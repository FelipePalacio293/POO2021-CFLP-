#ifndef CIRCULO_H
#define CIRCULO_H
#include "figuraGeometrica.h"

class Circulo : public FiguraGeometrica
{
	private:
		float radio;
	public:
		Circulo();
		Circulo( float );
	 	void calcularAreaCirculo();
	 	void calcularPerimetroCirculo();
	 	float getRadio();
	 	void setRadio(float);
};

#endif
