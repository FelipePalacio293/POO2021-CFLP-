#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include "cliente.h"
#include "ventas.h"
#include <list>

using std::list;

class Tienda
{
private:
    string nombre;
    string nombreDueno;
    int capClient;
    int capProducto;
    list<Producto> listaProductos; //list<Clase> nombre_de_lista
    list<Cliente> listaCliente;
    list<Venta> listaVentas;

    void setDummyData(); //Datos de prueba.

public:
    Tienda();
    void setNombre();
    void setDueno();
    void mostrarTodosProducto();
    void mostrarTodosCliente();
    void agregarProducto();
    void vender();
    void mostrarTodasLasVentas();
    Producto buscarProductoId(int);
    Cliente buscarClienteId(int);
};

#endif