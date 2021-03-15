#ifndef JURADO_H
#define JURADO_H

#include <iostream>
#include <list>
#include "persona.h"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

enum TipoJurado{
    interno = 1,
    externo = 2
};

class Jurado : public Persona{
    private:
        TipoJurado tipoJurado;
    public:
        Jurado(string, string, int, int, string, int);
        Jurado();
        void definirCalificaciones();
};

#endif