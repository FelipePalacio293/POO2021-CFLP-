#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// CLASE PRODUCTO

class Producto
{
private:
    string marca;
    string tipoProducto;
    int codigoProducto;
    int existencia;
    float valorProducto;
    float porcIVA;
public:
    Producto();
    Producto(string, string, int, int, float, float);
    void mostrarProducto();
    void setId(int);
    void setExistencia(int);
    int getId();
    int getExistencia();
    float getPrecio();
    float getIVA();
    string getNombre();
    string getTipoProducto();
};

#endif