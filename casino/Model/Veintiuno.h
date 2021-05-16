//
// Created by pc1 on 15/05/2021.
//

#ifndef CASINO_VEINTIUNO_H
#define CASINO_VEINTIUNO_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>

class Veintiuno : public Juego{
protected:
    int cartaJugador;
    int sumaPuntaje = 0;
    float calcularResultado(float gonzosApostar) override;

public:
    float jugar(float gonzosApostar) override;
    virtual ~Veintiuno();
};


#endif //CASINO_VEINTIUNO_H
