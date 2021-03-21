#include "criterio.h"

Criterio::Criterio(){

}

Criterio::Criterio(string descripcionCriterio, float ponderado){
    this->descripcionCriterio = descripcionCriterio;
    this->ponderado = ponderado;
}

void Criterio::setDescripcionCriterio(string descripcionCriterio){
    this->descripcionCriterio = descripcionCriterio;
}

void Criterio::setPonderado(float ponderado){
    this->ponderado = ponderado;
}

void Criterio::mostrarDescripcion(){
    cout << this->descripcionCriterio << endl;
}

float Criterio::getPonderado(){
    return this->ponderado;
}

string Criterio::getDescripcion(){
    return this->descripcionCriterio;
}