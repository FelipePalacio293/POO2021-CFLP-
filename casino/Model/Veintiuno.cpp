//
// Created by pc1 on 15/05/2021.
//

#include "Veintiuno.h"

float Veintiuno::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)
    int opcion;
    do{
        cartaJugador = 1 + rand() % 11; // numeros de 1 a 11
        sumaPuntaje += cartaJugador;
        cout << "Su carta fue: " << cartaJugador << "\n";
        cout << "Su acumulado es: " << sumaPuntaje << "\n";
        cout << "Si desea retirarse ingrese 0, de lo contrario, cualquiera otro numero\n";
        cin >> opcion;
    } while(opcion != 0 && sumaPuntaje < 21);
    float gonzosGanados = calcularResultado(gonzosApostar);
    return gonzosGanados;
}

float Veintiuno::calcularResultado(float gonzosApostar) {
    // Si el puntaje del jugador se pasa de 21, pierde todo o si el puntaje del usuario esta en el rango de 0 a 10 pierde todo
    // Si el puntaje del jugador es mayor o igual a 15 y menor a 21 gana 0.5
    // Si el puntaje del usuario esta en el rango de 10 a 15 no gana ni pierde
    // Si el puntaje del usuario es 21 gana por 5
    if(sumaPuntaje == 21){
        return gonzosApostar * 5;
    }
    else if(sumaPuntaje >= 15 && sumaPuntaje < 21){
        return gonzosApostar * 0.5;
    }
    else if(sumaPuntaje >= 10 && sumaPuntaje < 15){
        return gonzosApostar * 0.2;
    }
    else{
        return 0;
    }
}

Veintiuno::~Veintiuno(){

}
