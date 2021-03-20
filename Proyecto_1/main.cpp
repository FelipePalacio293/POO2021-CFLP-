#include "maestria.h"

#include <list>

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void mostrarMenu(){
    cout << "1. Crear acta." << endl;
    cout << "2. Crear persona." << endl;
    cout << "3. Crear jurado." << endl;
    cout << "4. Diligenciar criterios." << endl;
    cout << "5. Diligenciar calificaciones." << endl;
    cout << "6. Diligenciar comentarios." << endl;
}

void menu(){
    int opc;
    Maestria maestria;
    maestria.setDummyData();
    do
    {
        mostrarMenu();
        cin >> opc;
        switch(opc){
            case 1:
                maestria.crearActa();
                break;
            case 2:
                maestria.crearPersona();
                break;
            case 3:
                maestria.crearJurado();
                break;
            case 4:
                maestria.crearCriterios();
                break;
            case 5:
                maestria.diligenciarCalificaciones();
                break;
            case 6:
                maestria.mostrarTodosLosCriterios();
                break;
            case 7:
                maestria.diligenciarComentarios();
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while ( opc != -1 );

}

int main(){
    menu();
}