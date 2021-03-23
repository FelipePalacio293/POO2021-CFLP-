#ifndef JURADO_H
#define JURADO_H

#include <iostream>
#include <list>
#include "persona.h"
#include "detalleCriterio.h"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

enum TipoJurado{
    interno = 1,
    externo = 2
};

class Jurado : public Persona{ // La clase jurado toma todos los métodos y atributos de la clase persona
    private:
        TipoJurado tipoJurado; // Tiene también sus propios atributos y métodos
    public:
        Jurado(string, string, int, int, string, int);
        Jurado();
        DetalleCriterio definirCalificaciones(DetalleCriterio);
        void mostrarJurado();
        TipoJurado getTipoJurado();
};

#endif