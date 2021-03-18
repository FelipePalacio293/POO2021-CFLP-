#include <iostream>

using namespace std;

class Persona{
    private:
        string nombre;
        string email;
        int id;
        int celular;
    public:
        Persona();
        Persona(string, string, int, int);
        void mostrarDatos();
};

Persona::Persona(){
}

Persona::Persona(string nombre, string email, int id, int celular){
    this->nombre = nombre;
    this->email = email;
    this->id = id;
    this->celular = celular;
}

void Persona::mostrarDatos(){
    cout << "Datos" << this->nombre << endl;
    cout << this->email << endl;
    cout << this->id << endl;
    cout << this->celular << endl;
}

enum TipoJurado{
    interno = 1,
    externo = 2
};

class Jurado : public Persona{
    private:
        TipoJurado tipoJurado;
    public:
        Jurado(string, string, int, int, int);
        Jurado();
        void definirCalificaciones();
        void mostrarJurado();
};


Jurado::Jurado(){

}

Jurado::Jurado(string nombre, string email, int id, int celular, int tipoJurado) : Persona(nombre, email, id, celular){
    if(tipoJurado == 1){
        this->tipoJurado = externo;
    }
    else{
        this->tipoJurado = interno;
    }
}

void Jurado::mostrarJurado(){
    mostrarDatos();
    cout << tipoJurado << endl;
}

enum EstadoActa{
    abierto = 1, cerrado
};

int main(){
    return 0;
}