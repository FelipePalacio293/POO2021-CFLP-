#include "jurado.h"

Jurado::Jurado(){

}

Jurado::Jurado(string nombre, string email, int id, int celular, int tipoJurado) : Persona(nombre, email, id, celular){
    if(tipoJurado == 1){
        this->tipoJurado = externo;
    }
    else{
        this->tipoJurado = interno;
    }
}