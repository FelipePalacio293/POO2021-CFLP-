#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class DetalleVenta
{
private:
    string producto;
    float valor;
    float IVA;
    int cantidadProducto;
public:
    DetalleVenta();
    DetalleVenta(string, float, float, int);
};

#endif