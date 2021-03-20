#ifndef MAESTRIA_H
#define MAESTRIA_H

#include <iostream>
#include <list>

#include "jurado.h"
#include "acta.h"

using std::getline;

class Maestria{
    private:
        list<Acta> listaActas;
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
};

#endif