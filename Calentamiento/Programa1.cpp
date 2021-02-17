#include <iostream>
using namespace std;

int calcularIvaProducto(int precio){
    int iva;
    iva = precio * 0.19;
    return iva;
}

int main(){
    int precio;
    cout << "Ingrese el precio de un producto ";
    cin >> precio;
    precio += calcularIvaProducto(precio);
    cout << "El precio final del producto (con IVA) es: " << precio << endl;
}
