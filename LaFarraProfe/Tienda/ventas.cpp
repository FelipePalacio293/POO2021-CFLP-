#include "ventas.h"

Venta::Venta()
{
}

Venta::Venta(string cliente, int fecha, float valorTotal, DetalleVenta listaDetalles, float IVATotal, int id)
{
    this->cliente = cliente;
    this->fecha = fecha;
    this->valorTotal = valorTotal;
    this->listaDetalles = listaDetalles;
    this->IVATotal = IVATotal;
    this->id = id;
}

void Venta::crearDetalleVenta(string producto, float valor, float IVA, int cantidadProducto)
{
    this->listaDetalles.push_back();
}