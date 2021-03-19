#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <list>

using std::getline;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Criterio{
    private:
        string descripcionCriterio;
        float ponderado;
    public:
        Criterio();
        Criterio(string, float);
        void setDescripcionCriterio(string);
        void setPonderado(float);
        void mostrarDescripcion();
};

#endif