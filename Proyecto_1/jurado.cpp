#include "jurado.h"

Jurado::Jurado(){

}

Jurado::Jurado(string nombre, string email, int id, int celular, string rol, int tipoJurado) : Persona(nombre, email, id, celular, rol){
    if(tipoJurado == 1){
        this->tipoJurado = externo;
    }
    else{
        this->tipoJurado = interno;
    }
}

void Jurado::definirCalificaciones(){
    
}

TipoJurado Jurado::getTipoJurado(){
    return this->tipoJurado;
}

void Jurado::mostrarJurado(){
    mostrarPersona();
    cout << "Tipo jurado: " << getTipoJurado() << endl;
}