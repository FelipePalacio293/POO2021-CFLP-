//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    srand(time(NULL));
    numeroJugador = 1 + rand() % 14;
    cout << "Tu numero aleatorio es: "<< numeroJugador << "\n";
    cout << "Desea que se genere el numero del casino?\n1. Si\n 0. No\n" ;
    cin >> continuar;
    if(continuar){
        numeroCasino = 1 + rand() % 14;
    }
    float gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if(!continuar){
        return gonzosApostar * 0.5;
    }
    else if(numeroJugador <= numeroCasino){
        return 0;
    }
    else{
        return gonzosApostar * 2;
    }
}

Mayor13::~Mayor13() {

}
