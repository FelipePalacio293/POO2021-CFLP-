#include "maestria.h"

Maestria::Maestria(){
}

Persona Maestria::buscarPersona(int id){
    for(list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
    Persona persona;
    persona.setId(0);
    return persona;
}

Jurado Maestria::buscarJurado(int id){
    for(list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
    Jurado jurado;
    jurado.setId(0);
    return jurado;
}

void Maestria::crearPersona(){
    int id, celular;
    string nombre, email, rol;

    cout << "Ingrese el id de la persona " << endl;
    cin >> id;

    cout << "Ingrese el nombre de la persona " << endl;
    getline(cin, nombre);

    cout << "Ingrese email de la persona " << endl;
    getline(cin, email);

    cout << "Ingrese el celular de la persona " << endl;
    cin >> celular;

    cout << "Ingrese el rol de la persona " << endl;
    cin >> rol;

    listaPersonas.push_back(Persona(nombre, email, id, celular, rol));
}

void Maestria::crearJurado(){
    int id, celular, tipoJurado;
    string nombre, email, rol;
    cout << "Ingrese el id del jurado " << endl;
    cin >> id;

    cout << "Ingrese el nombre del jurado" << endl;
    getline(cin, nombre);

    cout << "Ingrese email del jurado " << endl;
    getline(cin, email);

    cout << "Ingrese el celular del jurado " << endl;
    cin >> celular;

    cout << "Ingrese el rol del jurado " << endl;
    cin >> rol;

    cout << "El jurado es: \n1. Interno\n2. Externo" << endl;
    cin >> tipoJurado;

    listaJurados.push_back(Jurado(nombre, email, id, celular, rol, tipoJurado));
}

void Maestria::crearActa(){
    int id, idPersona, opc, idJuradoUno, idJuradoDos, idDirector, idCodirector, tipoTrabajo;
    string fecha, nombreDelTrabajo;
    Persona autor, director, codirector;
    Jurado juradoUno, juradoDos;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> id;

    cout << "Ingrese nombre del trabajo:" << endl;
    getline(cin, nombreDelTrabajo);

    cout << "Ingrese la fecha: " << endl;
    getline(cin, fecha);

    cout << "Ingrese el ID del autor: " << endl;
    cin >> idPersona;

    cout << "Ingrese el tipo de trabajo\n1. Aplicado\n2. De investigacion" << endl;
    cin >> tipoTrabajo;

    autor = buscarPersona(idPersona);
    if(!autor.verificarExistenciaPersona()){
        cout << "No se encontro la persona. Se creara una." << endl;
        crearPersona();
        autor = *listaPersonas.end();
    }

    cout << "Ingresde el id del jurado uno" << endl;
    cin >> idJuradoUno;

    juradoUno = buscarJurado(idJuradoUno);
    if(!juradoUno.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearJurado();
        juradoUno = *listaJurados.end();
    }
    
    cout << "Ingresde el id del jurado dos" << endl;
    cin >> idJuradoDos;

    juradoDos = buscarJurado(idJuradoDos);
    if(!juradoDos.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearJurado();
        juradoDos = *listaJurados.end();
    }

    cout << "Ingresde el id del director" << endl;
    cin >> idDirector;

    director = buscarPersona(idDirector);
    if(!director.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearPersona();
        director = *listaPersonas.end();
    }

    cout << "Existe codirector\n1. Si\n2. No" << endl;
    cin >> opc;
    if( opc == 1 ){
        cout << "Ingresde el id del codirector" << endl;
        cin >> idCodirector;
        
        codirector = buscarPersona(idCodirector);

        if(!codirector.verificarExistenciaPersona()){
            cout << "No se encontro el jurado.Se creara una." << endl;
            crearPersona();
            codirector = *listaPersonas.end();
        }
    }

    this->listaActas.push_back(Acta(id, fecha, autor, nombreDelTrabajo, juradoUno, juradoDos, director, codirector, tipoTrabajo));
}