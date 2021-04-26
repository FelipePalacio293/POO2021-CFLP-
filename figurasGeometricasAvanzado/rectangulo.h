#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "figuraGeometrica.h"

class Rectangulo : public FiguraGeometrica
{
	private:
		float ancho, largo;
	public:
		Rectangulo();
		Rectangulo(float, float);
		void calcularAreaRectangulo();
		void calcularPerimetroRectangulo();
		float getAncho();
		void setAncho(float);
		float getLargo();
		void setLargo(float);
};

#endif