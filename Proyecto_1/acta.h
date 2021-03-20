#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "jurado.h"
#include "detalleCriterio.h"

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
    cerrado,
    abierto
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
        list<DetalleCriterio> detallesCriterios;
        int puedeCalificarse;
        float notaFinal;
    public:
        Acta();
        Acta(int, string, Persona, string, Jurado, Jurado, Persona, Persona, int);
        void setEstadoActa();
        void calificarActa();
        void setListaDetalles(list<DetalleCriterio>);
        int getNumero();
        Jurado getJuradoUno();
        Jurado getJuradoDos();
        list<DetalleCriterio> getListaDetalles();
        void ingresarComentarios();
        void ingresarCaLificaciones();
        void llenarCriterios();
        void mostrarDetalleCriterio();
        void sacarNotaFinalActa();
        void definirEstadoCalificacion();
        void cerrarActa();
        void mostrarDatos();
        EstadoActa getEstadoActa();
};
#endif