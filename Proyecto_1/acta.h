#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "jurado.h"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

enum TipoDeTrabajo{
    aplicado, 
    investigacion
};
enum EstadoActa{
    rechazado,
    aprobado
};
enum EstadoCalificacion{
    aprobado,
    pendiente,
    rechazado
};

class Acta{
    private:
        int numero;
        string fecha;
        Persona autor;
        string nombreTrabajo;
        Jurado juradoUno;
        Jurado juradoDos;
        Persona director;
        Persona codirector;
        int numeroDeCriterios;
        TipoDeTrabajo tipoTrabajo;
        EstadoActa estadoActa;
        EstadoCalificacion estadoCalificacion;
    public:
        Acta();
        Acta(int, string, Persona, string, Jurado, Jurado, Persona, Persona, int);


};
#endif