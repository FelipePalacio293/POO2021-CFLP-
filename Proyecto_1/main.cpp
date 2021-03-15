#include "jurado.h"
#include "acta.h"

#include <list>

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void mostrarMenu(){
    cout << "1. Agregar persona." << endl;
    cout << "2. Agregar jurado." << endl;
    cout << "3. Crear acta." << endl;
    cout << "4. XXXX." << endl;
    cout << "5. XXXXX." << endl;
}

void menu(){
    int opc;
    list<Acta> actas;
    do
    {
        mostrarMenu();
        cin >> opc;
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while ( opc != -1 );
    
}

int main(){
    menu();
}