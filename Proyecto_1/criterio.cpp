#include "criterio.h"

Criterio::Criterio(){

}

Criterio::Criterio(string descripcionCriterio, float ponderado){
    this->descripcionCriterio = descripcionCriterio;
    this->ponderado = ponderado;
}