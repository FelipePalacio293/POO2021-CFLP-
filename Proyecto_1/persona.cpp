	#include "persona.h"

Persona::Persona(){
}

Persona::Persona(string nombre, string email, int id, int celular){
    this->nombre = nombre;
    this->email = email;
    this->id = id;
    this->celular = celular;
}
