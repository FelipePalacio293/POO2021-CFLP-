#ifndef DETALLECRITERIO_H
#define DETALLECRITERIO_H

#include "criterio.h"

class DetalleCriterio{
    private:
        Criterio criterio;
        float notaJuradoUno;
        float notaJuradoDos;
        string comentarios;
        float notaPonderado;
        float notaPromedio;
    public:
        DetalleCriterio();
        DetalleCriterio(Criterio, float, float, string);
        void crearCriterio();
        void setNotaJuradoUno(float);
        void setNotaJuradoDos(float);
        void definirCriterio();
        void mostrarCriterio();
        void setComentario(string);
};

#endif