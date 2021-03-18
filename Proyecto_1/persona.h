#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Persona{
    private:
        string nombre;
        string email;
        int id;
        int celular;
        string rol;
    public:
        Persona();
        Persona(string, string, int, int, string);
        void mostrarPersona();
        int getId();
        void setId(int);
        string getNombre();
        string getEmail();
        int getCelular();
        string getRol();
        int verificarExistenciaPersona();
};

#endif