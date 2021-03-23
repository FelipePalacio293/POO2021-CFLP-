#include "persona.h"

Persona::Persona(){
}

// Constructor de la clase persona
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

string Persona::getNombre(){
    return this->nombre;
}

string Persona::getEmail(){
    return this->email;
}

int Persona::getCelular(){
    return this->celular;
}

string Persona::getRol(){
    return this->rol;
}

int Persona::verificarExistenciaPersona(){
    if(this->id == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void Persona::mostrarPersona(){
    cout << "Id: " << getId() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Celular: " << getCelular() << endl;
    cout << "Rol: " << getRol() << endl;
}