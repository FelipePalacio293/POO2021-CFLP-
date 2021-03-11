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
    Producto tempProduc;
    for(list<Producto>::iterator it = listaProductos.begin(); it != listaProductos.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
    tempProduc.setId(000);
    return tempProduc;
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
    Cliente cliente;
    cliente.setId(000);
    return cliente;
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

void Tienda::mostrarTodasLasVentas()
{
    for(list<Venta>::iterator it = listaVentas.begin(); it != listaVentas.end(); it++)
    {
        it->mostrarVenta();
    }
}

void Tienda::vender()
{
    int opc = 0, codigoProducto, codigoCliente, cantidadProducto, idVenta;
    float valorTotalProducto, valorTotalVenta = 0, IVAproducto, contIVA = 0;
    Producto producto;
    Cliente cliente;
    Venta venta;
    string fecha;
    do
    {
        cout << "Digite codigo del producto: " << endl;
        cin >> codigoProducto; 
        producto = buscarProductoId(codigoProducto);

        // El id 0 se utiliza para especificar que el producto no existe

        if(producto.getId() == 000) 
        {
            cout << "El producto no existe" << endl;
            continue;
        }

        cout << "Digite la cantidad del producto: " << endl;
        cin >> cantidadProducto;

        if(producto.getExistencia() >= cantidadProducto)
        {
            IVAproducto = producto.getPrecio() * producto.getIVA();
            contIVA += IVAproducto;
            valorTotalProducto = (producto.getPrecio() * cantidadProducto) + (IVAproducto * cantidadProducto);
            valorTotalVenta += valorTotalProducto;
            venta.crearDetalleVenta(producto, valorTotalProducto, IVAproducto, cantidadProducto);
            producto.setExistencia(producto.getExistencia() - cantidadProducto);
        }
        else
        {
            cout << "Insuficientes unidades del producto" << endl;
        }
        cout << "Digite cualquier numero para continuar (-1 Para salir): " << endl;
        cin >> opc;

    } while( opc != -1 );

    do
    {
        cout << "Digite codigo del cliente: " << endl;
        cin >> codigoCliente;
        cliente = buscarClienteId(codigoCliente);
    } while ( cliente.getId() == 0 );
    
    venta.setCliente(cliente);
    // To do: Revisar fecha y hora automática con la librería ctime
    venta.setFecha(fecha);
    venta.setId(idVenta);
    venta.setIVATotal(contIVA);
    venta.setValorTotal(valorTotalVenta);

    listaVentas.push_back(venta);
}