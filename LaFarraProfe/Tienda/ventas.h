#ifndef VENTAS_H
#define VENTAS_H

#include <iostream>
#include "DetalleVenta.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Venta
{
private:
    string cliente;
    int fecha;
    float valorTotal;
    list<DetalleVenta> listaDetalles;
    float IVATotal;
    int id;
public:
    Venta();
    Venta(string, int, int, DetalleVenta, float, int);
    void crearDetalleVenta(string, float, float, int);
};

#endif