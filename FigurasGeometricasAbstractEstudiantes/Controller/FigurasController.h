#ifndef FIGURASCONTROLLER_H
#define FIGURASCONTROLLER_H

#include "../Model/FiguraGeometrica.h"
#include "../Model/Circulo.h"
#include "../Model/Triangulo.h"
#include "../Model/Rectangulo.h"
#include "../Model/Cuadrado.h"

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class FigurasController
{
private:
    //constante y estático para declararla constante para todos los objetos.
    const static int MAX_ITEMS;
    list<Rectangulo> listaRectangulo;
    list<Circulo> listaCirculo;
    list<Triangulo> listaTriangulo;
    list<FiguraGeometrica *> listaFiguras;
public:
    // Retorna referencia a la lista de rectangulos
    list<Rectangulo> &getListaRectangulo();
    void agregarRectangulo(float largo, float ancho);

    /**
       * Retorna la referencia al rectangulo que tenga el mayor ancho       
       *
    */
    Rectangulo &encontrarMayorAncho();

    // TO-DO

    list<Rectangulo> &getListaCirculo();
    void agregarTriangulo(float base, float altura);
    void agregarCirculo(float radio);
    void agregarCuadrado(float lado);
    list<FiguraGeometrica *> &getListaFiguras();
};
//#define FIGURAS_CONTROLLER_H
#endif // FIGURASCONTROLLER_H
