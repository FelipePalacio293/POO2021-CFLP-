#include <iostream>
using namespace std;

int pedirEdad(){
    int edad;
    cout << "Ingrese la edad de la persona: ";
    cin >> edad;
    return edad;
}

string pedirSexo(){
    string sexo;
    cout << "Ingrese el sexo de la persona: ";
    cin >> sexo;
    return sexo;
}

float pedirAltura(){
    float altura;    
    cout << "Ingrese la altura de la persona: ";
    cin >> altura;
    return altura;
}

void mostrarDatos(){
    cout << "La persona tiene " << pedirEdad() << " anios, de sexo " << pedirSexo() << " y altura " << pedirAltura() << " metros" << endl;
}

int main(){
    mostrarDatos();
}