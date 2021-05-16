//
// Created by lufe0 on 7/05/2021.
//

#include "Jugador.h"

Jugador::Jugador()
          :cantJuegos(0)
{
}
// Hace llamada delegada al constructor por defecto
Jugador::Jugador(long id, string nombre, float cantGonzos): Jugador() {
    this->id = id;
    this->nombre = nombre;
    this->cantGonzos = cantGonzos;
}


/* Destructor*/
Jugador::~Jugador()
{
}

void Jugador::mostrarInfo() {

    // Muestra el nombre , la cantidad de gonzos y la cantidad de juegos jugados
    cout << "Nombre: "<< this->nombre << endl;
    cout << "Id: "<< this->id << endl;
    cout << "Sus gonzos: "<< this->cantGonzos << endl;
    cout << "Numero de juegos: " << this->cantJuegos << endl;
}

void Jugador::aumentarJuegos() {
    // Incrementa la cantidad de juegos que ha jugado el jugador
    this->cantJuegos += 1;
}

void Jugador::actualizarGonzos(float resultadoJuego) {
    this->cantGonzos += resultadoJuego;
}

const string &Jugador::getNombre() const {
    return this->nombre;
}

float Jugador::getCantGonzos() const {
    return this->cantGonzos;
}

long Jugador::getId() const {
    return this->id;
}






