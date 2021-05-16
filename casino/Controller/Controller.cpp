//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"
#include "../Model/Veintiuno.h"

Controller::Controller() {
    this->casino = Casino();
    // Se agregan los juegos disponibles para el casino
    Mayor13 * juego1 = new Mayor13();
    DosColores * juego2 = new DosColores();
    Veintiuno * juego3 = new Veintiuno();
    casino.agregarJuego(juego1);
    casino.agregarJuego(juego2);
    casino.agregarJuego(juego3);
}

void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador * pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador) == false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }

    // Si no hay errores se inicia el juego

    int posJuego = idJuego - 1; // Se corrige la posicion para acceder al juego
    Juego * pJuegoAJugar = casino.consultarJuegos().at(posJuego);

    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    // Actualiza el saldo del jugador con el resultado
    // Actualiza la cantidad de juegos jugados
    // Retorna verdadero si el jugador ganó y false si el jugador perdio

    float resultado;
    map<long, Jugador *> jugadoresMap = casino.getJugadoresMap();
    try {
        if(gonzosApostar > jugadoresMap[idJugador]->getCantGonzos()){
            throw std::domain_error("No tienes saldo suficiente para jugar\n");
        }
    } catch (std::domain_error ex) {
        cout << ex.what();
    }
    
    jugadoresMap[idJugador]->actualizarGonzos(-gonzosApostar);
    resultado = pJuegoAJugar->jugar(gonzosApostar);

    cout << "Usted ha ganado: " << resultado << " gonzos\n";

    jugadoresMap[idJugador]->actualizarGonzos(resultado);
    jugadoresMap[idJugador]->aumentarJuegos();

    if(resultado == 0){
        return false;
    }
    else{
        return true;
    }
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    casino.retirarJugador(idJugador);
}

void Controller::recargarGonzos(long idJugador) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    int dinero;
    do {
        cout << "Ingrese el dinero a recargar\n";
        cin >> dinero;
    } while (dinero <= 0);
    srand(time(NULL));
    Jugador *pJugador = casino.consultarJugador(idJugador);
    float gonzosRecargados = casino.convertirPesosAGonzos(dinero);
    int numeroAleatorio = 1 + rand() % 10;
    if(numeroAleatorio > 5){
        gonzosRecargados *= 2;
    }
    cout << "Se recargaron con exito los gonzos\n";
    pJugador->actualizarGonzos(gonzosRecargados);
}

void Controller::venderGonzos(long idJugador) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    float gonzosCambio;
    do {
        cout << "Ingrese los gonzos a cambiar\n";
        cin >> gonzosCambio;
    } while (gonzosCambio > pJugador->getCantGonzos());
    float dineroSacado = casino.convertirGonzosPesos(gonzosCambio);
    cout << "Su dinero es: " << dineroSacado << "\n";
    pJugador->actualizarGonzos(-gonzosCambio);
}

