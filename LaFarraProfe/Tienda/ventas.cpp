#include "ventas.h"

Venta::Venta()
{
}

Venta::Venta(Cliente cliente, string fecha, float valorTotal, DetalleVenta listaDetalles, float IVATotal, int id)
{
    this->cliente = cliente;
    this->fecha = fecha;
    this->valorTotal = valorTotal;
    this->listaDetalles = listaDetalles;
    this->IVATotal = IVATotal;
    this->id = id;
}

void Venta::crearDetalleVenta(Producto producto, float valor, float IVA, int cantidadProducto)
{
    this->listaDetalles.push_back(DetalleVenta(producto, valor, IVA, cantidadProducto));
}

void Venta::setCliente(Cliente cliente)
{
    this->cliente = cliente;
}

void Venta::setFecha(string fecha)
{
    this->fecha = fecha;
}

void Venta::setId(int id)
{
    this->id = id;
}

void Venta::setIVATotal(float IVATotal)
{
    this->IVATotal = IVATotal;
}

void Venta::setValorTotal(float valorTotal)
{
    this->valorTotal = valorTotal;
}