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
        DetalleCriterio(string, float);
        DetalleCriterio(Criterio, float, float, string);
        void crearCriterio();
        void setNotaJuradoUno(float);
        void setNotaJuradoDos(float);
        void definirCriterio();
        void mostrarCriterio();
        void setComentario(string);
        void calcularNotaPonderado();
        void calcularNotaPromedio();
        float getNotaPromedio();
        string getDescripcionCriterio();
        float getPonderadoCriterio();
        string getComentario();
};

#endif