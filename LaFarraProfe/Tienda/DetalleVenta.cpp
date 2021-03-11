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

void DetalleVenta::mostrarDetallesVentas()
{
    cout << "==================" << endl;
    cout << this->producto.getNombre() << endl;
    cout << this->valor << endl;
    cout << this->IVA << endl;
    cout << this->cantidadProducto << endl;
}