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
                break;
            case 11:
                maestria.listarActasPorEstado();
                break;
            case 12:
                maestria.mostrarTrabajosPorTipo(aplicado);
                break;
            case 13:
                maestria.mostrarTrabajosPorTipo(investigacion);
                break;
            case 14:
                maestria.mostrarTrabajosPorProfesor();
                break;
            case 15:
                maestria.mostrarTrabajoPorJurado();
                break;
            case 16:
                maestria.mostrarTodosLosJurados();
                break;
            case 17:
                maestria.mostrarActasPorEstadoCalificacion();
                break;
            case 18:
                maestria.consultarJuradosPorTipo(interno);
                break;
            case 19:
                maestria.consultarJuradosPorTipo(externo);
                break;
            case 20:
                maestria.eliminarActa();
                break;
            case 21:
                maestria.generarArchivoDeTexto();
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while ( opc != -1 );
}

int main(){
    menu();
}