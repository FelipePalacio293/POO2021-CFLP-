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
    cout << "11. Listar las actas por estado." << endl;
    cout << "12. Consultar cuantos y cuales trabajos estan relacionados con industria." << endl;
    cout << "13. Consultar cuantos y cuales trabajos estan relacionados con investigacion." << endl;
    cout << "14. Consultar trabajos dados por un profesor." << endl;
    cout << "15. Consultrar trabajos dados por un jurado." << endl;
    cout << "16. Mostrar todos los jurados." << endl;
    cout << "17. Mostrar las actas rechazadas y pendientes." << endl;
    cout << "18. Consultar jurados externos." << endl;
    cout << "19. Consultar jurados internos." << endl;
    cout << "20. Eliminar un acta." << endl;
    cout << "21. Generar archivo de texto con los datos." << endl;
}

// Se crea un método menú y una variable maestría donde se llaman todas las funciones del programa

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
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 2:
                maestria.crearPersona();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 3:
                maestria.crearJurado();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 4:
                maestria.crearCriterios();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 5:
                maestria.diligenciarCalificaciones();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 6:
                maestria.mostrarTodosLosCriterios();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 7:
                maestria.diligenciarComentarios();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 8:
                maestria.obtenerNotaFinalDeUnActa();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 9:
                maestria.cerrarUnActa();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 10:
                maestria.mostrarTodasLasActas();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 11:
                maestria.listarActasPorEstado();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 12:
                maestria.mostrarTrabajosPorTipo(aplicado);
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 13:
                maestria.mostrarTrabajosPorTipo(investigacion);
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 14:
                maestria.mostrarTrabajosPorProfesor();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 15:
                maestria.mostrarTrabajoPorJurado();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 16:
                maestria.mostrarTodosLosJurados();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 17:
                maestria.mostrarActasPorEstadoCalificacion();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 18:
                maestria.consultarJuradosPorTipo(interno);
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 19:
                maestria.consultarJuradosPorTipo(externo);
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 20:
                maestria.eliminarActa();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            case 21:
                maestria.generarArchivoDeTexto();
                cout << "==========================" << endl;
                cout << "Instruccion finalizada" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while ( opc != -1 );
}

int main(){
    menu();
}