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
    cout << "6. Mostrar todos los criterios." << endl;
    cout << "7. Diligenciar comentarios." << endl;
    cout << "8. Obtener nota final de un acta." << endl;
    cout << "9. Cerrar acta." << endl;
    cout << "10. Mostrar todas las actas." << endl;
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
            case 8:
                maestria.obtenerNotaFinalDeUnActa();
                break;
            case 9:
                maestria.cerrarUnActa();
                break;
            case 10:
                maestria.mostrarTodasLasActas();
            default:
                cout << "Opcion invalida" << endl;
        }
    } while ( opc != -1 );
}

int main(){
    menu();
}