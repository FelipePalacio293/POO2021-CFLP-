#include "detalleCriterio.h"

DetalleCriterio::DetalleCriterio(){

}

DetalleCriterio::DetalleCriterio(string descripcion, float ponderado){

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

// Método que define los atributos de la variable criterio dentro de la clase detalleCriterio,
// haciendo uso de los sets.
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

void DetalleCriterio::calcularNotaPonderado(){
    this->notaPonderado = (this->notaJuradoUno + this->notaJuradoUno) * criterio.getPonderado() / 100;
}

void DetalleCriterio::calcularNotaPromedio(){
    this->notaPromedio = ((this->notaJuradoUno + this->notaJuradoDos) / 2);
}

float DetalleCriterio::getNotaPromedio(){
    return this->notaPromedio;
}

string DetalleCriterio::getDescripcionCriterio(){
    return this->criterio.getDescripcion();
}

float DetalleCriterio::getPonderadoCriterio(){
    return this->criterio.getPonderado();
}

string DetalleCriterio::getComentario(){
    return this->comentarios;
}