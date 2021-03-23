#ifndef MAESTRIA_H
#define MAESTRIA_H

#include <iostream>
#include <list>

#include "jurado.h"
#include "acta.h"

using std::getline;

class Maestria{
    private:
        list<Acta> listaActas; // Se definen las listas que almacenarán "todos" los datos del programa
        list<Jurado> listaJurados;
        list<Persona> listaPersonas;
    public:
        Maestria();
        Persona buscarPersona(int);
        Jurado buscarJurado(int);
        void crearActa();
        void crearJurado();
        void crearPersona();
        int verificarRolEstudiante(Persona);
        void diligenciarCalificaciones();
        Acta buscarActa(int);
        void crearCriterios();
        void setDummyData();
        void diligenciarComentarios();
        void mostrarTodosLosCriterios();
        void actualizarActa(int);
        void obtenerNotaFinalDeUnActa();
        void cerrarUnActa();
        void mostrarTodasLasActas();
        void listarActasPorEstado();
        void mostrarTrabajosPorTipo(TipoDeTrabajo);
        void mostrarTrabajosPorProfesor();
        void mostrarTrabajoPorJurado();
        void mostrarTodosLosJurados();
        void mostrarActasPorEstadoCalificacion();
        void consultarJuradosPorTipo(TipoJurado);
        void eliminarActa();
        void generarArchivoDeTexto();
        list<Acta>::iterator obtenerActa(int);
        int verificarExistenciaActa(int);
        void verificarComentariosAdicionales();
};

#endif