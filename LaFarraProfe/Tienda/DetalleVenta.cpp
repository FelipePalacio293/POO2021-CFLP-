#include "DetalleVenta.h"

DetalleVenta::DetalleVenta()
{    
}

DetalleVenta::DetalleVenta(Producto producto, float valor, float IVA, int cantidadProducto)
{
    this->producto = producto;
    this->valor = valor;
    this->IVA = IVA;
    this->cantidadProducto = cantidadProducto;
}