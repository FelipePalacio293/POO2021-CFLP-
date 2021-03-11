#ifndef VENTAS_H
#define VENTAS_H

#include <iostream>
#include <list>
#include "DetalleVenta.h"
#include "producto.h"
#include "Cliente.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Venta
{
private:
    Cliente cliente;
    string fecha;
    float valorTotal;
    list<DetalleVenta> listaDetalles;
    float IVATotal;
    int id;
public:
    Venta();
    Venta(Cliente, string, float, list<DetalleVenta>, float, int);
    void crearDetalleVenta(Producto, float, float, int);
    void setCliente(Cliente);
    void setFecha(string);
    void setValorTotal(float);
    void setIVATotal(float);
    void setId(int);
    void mostrarVenta();
};

#endif