#ifndef MAESTRIA_H
#define MAESTRIA_H

#include <iostream>
#include <list>

#include "jurado.h"
#include "acta.h"

class Maestria{
    private:
        list<Acta> listaActas;
        list<Jurado> listaJurados;
        list<Persona> listaPersonas;
    public:
        Acta buscarActa(int);
        Persona buscarPersona(int);
        Jurado buscarJurado(int);
        void crearActa();
        void crearJurado();
        void crearPersona();
};

#endif