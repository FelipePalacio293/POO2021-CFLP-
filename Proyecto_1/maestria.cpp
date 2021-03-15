#include "maestria.h"

Maestria::Maestria(){
}

Persona Maestria::buscarPersona(int id){
    int opc;
    for(list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }

    cout << "La persona no ha sido encontrada, desea crear una?\n1. Si\n2. No" << endl;
    cin >> opc;

    if( opc == 1 ){
        crearPersona();
        return *listaPersonas.end();
    }
}

void Maestria::crearPersona(){
    int id, celular;
    string nombre, email, rol;

    cout << "Ingrese el id de la persona " << endl;
    cin >> id;

    cout << "Ingrese el nombre de la persona " << endl;
    cin >> nombre;

    cout << "Ingrese email de la persona " << endl;
    cin >> email;

    cout << "Ingrese el celular de la persona " << endl;
    cin >> celular;

    cout << "Ingrese el rol de la persona " << endl;
    cin >> rol;

    listaPersonas.push_back(Persona(nombre, email, id, celular, rol));
    return;
}

void Maestria::crearActa(){
    int id;
    int idPersona;
    int opc;
    string fecha;
    int idJuradoUno;
    int idJuradoDos;
    int idDirector;
    int idCodirector;
    int tipoTrabajo;
    Persona autor;
    Persona director;
    Persona codirector;
    Jurado juradoUno;
    Jurado juradoDos;

    cout << "Ingrese el ID del acta: " << endl;
    cin >> id;

    cout << "Ingrese el ID del autor: " << endl;
    cin >> idPersona;

    cout << "Ingrese la fecha: " << endl;
    cin >> fecha;

    cout << "Ingresde el id del jurado uno" << endl;
    cin >> idJuradoUno;

    cout << "Ingresde el id del jurado dos" << endl;
    cin >> idJuradoDos;

    cout << "Ingresde el id del director" << endl;
    cin >> idJuradoDos;

    cout << "Existe codirector\n1. Si\n2. No" << endl;
    cin >> opc;

    if( opc == 1 ){
        cout << "Ingresde el id del codirector" << endl;
        cin >> idJuradoDos;
    }

    this->listaActas.push_back(Acta());
}