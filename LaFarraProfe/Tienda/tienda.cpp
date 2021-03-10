#include <iostream>
#include "tienda.h"

//CONSTRCUTORES TIENDA

Tienda::Tienda()
{
    this->nombre = "La Farra";
    this->nombreDueno = "POO";
    this->setDummyData();
}

void Tienda::setDummyData()
{
    this->listaCliente.push_back(Cliente("Luisa", "lufe089@gmail.com", 1020, "20202"));
    this->listaProductos.push_back(Producto("Pantene", "Shampoo", 01, 10, 8520, 0.30));
}

//METODOS TIENDA

void Tienda::mostrarTodosProducto()
{

    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;

    for (list<Producto>::iterator producto = listaProductos.begin(); producto != listaProductos.end(); producto++)
    {
        producto->mostrarProducto();
    }
}

void Tienda::mostrarTodosCliente()
{

    for (list<Cliente>::iterator it = listaCliente.begin(); it != listaCliente.end(); it++)
    {
        it->mostrarCliente();
    }
}

Producto Tienda::buscarProductoId(int id)
{
    for(list<Producto>::iterator it = listaProductos.begin(); it != listaProductos.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
}

Cliente Tienda::buscarClienteId(int id)
{
    for(list<Cliente>::iterator it = listaCliente.begin(); it != listaCliente.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
}

void Tienda::agregarProducto()
{
    string marca, tipoProducto;
    int codigo, existencia;
    float valorProducto, porcIVA;

    cout << "Digite marca: " << endl;
    cin >> marca;

    cout << "Digite tipo del producto: " << endl;
    cin >> tipoProducto;

    cout << "Digite codigo: " << endl;
    cin >> codigo;

    cout << "Digite existencia: " << endl;
    cin >> existencia;

    cout << "Digite valor del producto: " << endl;
    cin >> valorProducto;

    cout << "Digite el porcentaje de IVA: " << endl;
    cin >> porcIVA;

    listaProductos.push_back(Producto(marca, tipoProducto, codigo, existencia, valorProducto, porcIVA));
}

void Tienda::vender()
{
    int opc, codigoProducto, codigoCliente, cantidadProducto, codigoCliente, idVenta;
    float valorTotalProducto, valorTotalVenta, IVAproducto, contIVA = 0;
    Producto producto;
    Cliente cliente;
    Venta venta;
    string fecha;
    do
    {
        cout << "Digite codigo del producto: " << endl;
        cin >> codigoProducto;
        producto = buscarProductoId(codigoProducto);
        cout << "Digite la cantidad del producto: " << endl;
        cin >> cantidadProducto;
        IVAproducto = producto.getPrecio() * producto.getIVA();
        contIVA += IVAproducto;
        valorTotalProducto = (producto.getPrecio() * cantidadProducto) + (IVAproducto * cantidadProducto);
        valorTotalVenta += valorTotalProducto;
        venta.crearDetalleVenta(producto, valorTotalProducto, IVAproducto, cantidadProducto);
    } while(opc != -1);

    cout << "Digite codigo del producto: " << endl;
    cin >> codigoCliente;

    cliente = buscarClienteId(codigoCliente);

    venta.setCliente(cliente);
    venta.setFecha(fecha);
    venta.setId(idVenta);
    venta.setIVATotal(contIVA);
    venta.setValorTotal(valorTotalVenta);

    listaVentas.push_back(venta);
    // Se vende hasta que el cajero escriba menos uno

    // Se pide el codigo del producto
    // Se  busca el producto por código
    // Se pregunta cuantos se van a vender de ese producto
    // Se calcula el valor total de la venta de ese producto
    // Se agrega a la lista de detalle
    // Se agrega el valor total al gran total

    // Una vez terminado de agregar productos
    // Se pide el numero del cliente
    // Se busca el cliente
    // Se calcula la fecha y hora actual
    // Se crea un numero de factua
    // Se asocia la lista del detalle de la factura
    // Se crea el objeto venta, en la lista de ventas de la tienda.  (relación de composicion.)
}