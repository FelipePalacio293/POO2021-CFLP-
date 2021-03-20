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

void Acta::ingresarComentarios(){
    string comentarios;

    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++){
        cout << "Ingrese los comentarios de los jurados para el criterio:" << endl;
        it->mostrarCriterio();
        getline(cin, comentarios);
    }
}

void Acta::ingresarCaLificaciones(){
    float nota;
    cout << "He llegado hasta aqui 1" << endl;
    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++){
        cout << "Ingrese la nota del jurado uno para el criterio:" << endl;
        it->mostrarCriterio();
        cin >> nota;
        it->setNotaJuradoUno(nota);
        cout << "Ingrese la nota del jurado dos para el mismo criterio:" << endl;
        cin >> nota;
        it->setNotaJuradoDos(nota);
    }
}

void Acta::llenarCriterios(){
    int x;
    DetalleCriterio detalleCriterio;
    for(x = 0; x < 8; x++){
        detalleCriterio.definirCriterio();
        this->detallesCriterios.push_back(detalleCriterio);
    }
}

void Acta::mostrarDetalleCriterio(){
    DetalleCriterio detalleTemp;
    for(list<DetalleCriterio>::iterator it = detallesCriterios.begin(); it != detallesCriterios.end(); it++){
        it->mostrarCriterio();
    }
}