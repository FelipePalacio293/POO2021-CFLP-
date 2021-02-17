#include <iostream>
#include <fstream>
using namespace std;

struct agenda{
    string nombre;
    string apellido;
    int telefono;
}agendaTelefono[100]; 

void guardarContactosEnTxt(int numPersonas){
    int x;
    ofstream file;
    file.open("Agenda.txt");
    file << "Nombre Apellido Telefono\n";
    for(x = 0; x < numPersonas; x++ ){
        file << agendaTelefono[x].nombre << " " << agendaTelefono[x].apellido << " " << agendaTelefono[x].telefono << "\n";
    }
    file.close();
}

void crearContacto(int numPersonas){
    cout << "Ingrese el nombre del contacto: ";
    cin >> agendaTelefono[numPersonas].nombre;
    cout << "Ingrese el apellido del contacto: ";
    cin >> agendaTelefono[numPersonas].apellido;
    cout << "Ingrese el telefono del contacto: ";
    cin >> agendaTelefono[numPersonas].telefono;
}

void mostrarContactos(int numPersonas){
    int x;
    for(x = 0; x < numPersonas; x++ ){
        cout << "Nombre " << agendaTelefono[x].nombre << " Apellido " << agendaTelefono[x].apellido << " Telefono " << agendaTelefono[x].telefono << "\n";
    }
}

void menu(){
    int numPersonas = 0, opc = 1;
    do{ 
        cout << "Ingrese la opcion que desea:\n1. Crear contacto\n2. Agregar mas contactos\n3. Visualizar contactos\n";
        cin >> opc;
        switch(opc){
            case 1:
                crearContacto(numPersonas);
                numPersonas++;
                break;
            case 2:
                crearContacto(numPersonas);
                numPersonas++;
                break;
            case 3:
                mostrarContactos(numPersonas);
                break;
        }
    guardarContactosEnTxt(numPersonas);
    } while(opc != 0);
}

int main(){
    menu();
}