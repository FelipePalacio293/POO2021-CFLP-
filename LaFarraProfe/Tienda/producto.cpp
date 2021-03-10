#include "producto.h"

//**************  METODOS PRODUCTO ******************//
Producto::Producto()
{
}

//este constructor es para crear cada producto y añadirlo a la lista
Producto::Producto(string marca, string tipoProducto, int codigo, int exs, float valorProducto, float porcIVA)
{
    this->marca = marca;
    this->tipoProducto = tipoProducto;
    this->codigoProducto = codigo;
    this->existencia = exs;
    this->valorProducto = valorProducto;
    this->porcIVA = porcIVA;
}

void Producto::mostrarProducto()
{
    cout << "==================" << endl;
    cout << "Marca: " << this->marca << endl;
    cout << "Tipo: " << this->tipoProducto << endl;
    cout << "Codigo: " << this->codigoProducto << endl;
    cout << "Existencia: " << this->existencia << endl;
    cout << "Valor producto: " << this->valorProducto << "$" << endl;
}

int Producto::getId()
{
    return this->codigoProducto;
}

float Producto::getPrecio()
{
    return this->valorProducto;
}

float Producto::getIVA()
{
    return this->porcIVA;
}