#include "detalleCriterio.h"

DetalleCriterio::DetalleCriterio(){

}

void DetalleCriterio::crearCriterio(){
    string descripcionCriterio;
    float ponderado;
    cout << "Ingrese la descripcion del ponderado"  << endl;
    getline(cin, descripcionCriterio);
    cout << "Ingrese el porcentaje del ponderado"  << endl;
    cin >> ponderado;
    
    Criterio criterio(descripcionCriterio, ponderado);
    this->criterio = criterio;
}

void DetalleCriterio::setNotaJuradoUno(float nota){
    this->notaJuradoUno = nota;
}

void DetalleCriterio::setNotaJuradoDos(float nota){
    this->notaJuradoDos = nota;
}

void DetalleCriterio::definirCriterio(){
    string descripcion;
    float ponderado;
    cout << "Ingrese la descripcion del criterio:" << endl;
    cin.ignore();
    getline(cin, descripcion);
    cout << "Ingrese el % del ponderado" << endl;
    cin >> ponderado;
    this->criterio.setDescripcionCriterio(descripcion);
    this->criterio.setPonderado(ponderado);
}

void DetalleCriterio::mostrarCriterio(){
    this->criterio.mostrarDescripcion();
}

void DetalleCriterio::setComentario(string comentarios){
    this->comentarios = comentarios;
}