#include "acta.h"

Acta::Acta(){

}

Acta::Acta(int numero, string fecha, Persona autor, string nombreTrabajo, Jurado juradoUno, Jurado juradoDos, Persona director, Persona codirector, int tipoDeTrabajo){
    this->numero = numero;
    this->fecha = fecha;
    this->autor = autor;
    this->nombreTrabajo = nombreTrabajo;
    this->juradoUno = juradoUno;
    this->juradoDos = juradoDos;
    this->director = director;
    this->codirector = codirector;
    this->numeroDeCriterios = 8;
    this->estadoActa = abierto;
    this->estadoCalificacion = pendiente;
    if(tipoDeTrabajo == 1)
        this->tipoTrabajo = aplicado;
    else
        this->tipoTrabajo = investigacion;
}

void Acta::calificarActa(){
    int x;
    for(x = 0; x < this->numeroDeCriterios; x++){
        detallesCriterios.push_back(DetalleCriterio());
    }
}

int Acta::getNumero(){
    return this->numero;
}

Jurado Acta::getJuradoUno(){
    return this->juradoUno;
}

Jurado Acta::getJuradoDos(){
    return this->juradoDos;
}

void Acta::setListaDetalles(list<DetalleCriterio> detallesCriterios){
    this->detallesCriterios = detallesCriterios;
}

list<DetalleCriterio> Acta::getListaDetalles(){
    return this->detallesCriterios;
}