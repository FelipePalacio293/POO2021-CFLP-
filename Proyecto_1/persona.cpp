#include "persona.h"

Persona::Persona(){
}

Persona::Persona(string nombre, string email, int id, int celular, string rol){
    this->nombre = nombre;
    this->email = email;
    this->id = id;
    this->celular = celular;
    this->rol = rol;
}

int Persona::getId(){
    return this->id;
}

void Persona::setId(int id){
    this->id = id;
}

int Persona::verificarExistenciaPersona(){
    if(this->id == 0){
        return 0;
    }
    else{
        return 1;
    }
}