#include "maestria.h"

Maestria::Maestria(){
}

void Maestria::setDummyData(){
    listaPersonas.push_back(Persona("Santiago Grisales", "santi@gmail.com", 001, 32434, "Estudiante"));
    listaPersonas.push_back(Persona("Gerardo Sarria", "gerar@gmail.com", 002, 43435, "Director"));
    listaPersonas.push_back(Persona("Luisa Rincon", "lufe@gmail.com", 003, 34345, "Codirector"));
    listaJurados.push_back(Jurado("Fabian Ledezma", "Fabian@gmail.com", 004, 34345, "Jurado", 1));
    listaJurados.push_back(Jurado("Juan Orozco", "juan@gmail.com", 005, 465634, "Jurado", 1));
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
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese email de la persona " << endl;
    cin.ignore();
    getline(cin, email);

    cout << "Ingrese el celular de la persona " << endl;
    cin >> celular;

    cout << "Ingrese el rol de la persona " << endl;
    cin >> rol;

    listaPersonas.push_back(Persona(nombre, email, id, celular, rol));
}

void Maestria::crearJurado(){
    int id, celular, tipoJurado;
    string nombre, email, rol = "Jurado";
    cout << "Ingrese el id del jurado " << endl;
    cin >> id;

    cout << "Ingrese el nombre del jurado" << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese email del jurado " << endl;
    cin.ignore();
    getline(cin, email);

    cout << "Ingrese el celular del jurado " << endl;
    cin >> celular;

    cout << "El jurado es: \n1. Interno\n2. Externo" << endl;
    cin >> tipoJurado;

    listaJurados.push_back(Jurado(nombre, email, id, celular, rol, tipoJurado));
}

void Maestria::crearActa(){
    int idActa, idPersona, opc, idJuradoUno, idJuradoDos, idDirector, idCodirector, tipoTrabajo;
    string fecha, nombreDelTrabajo;
    Persona autor, director, codirector;
    Jurado juradoUno, juradoDos;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    cout << "Ingrese nombre del trabajo:" << endl;
    cin.ignore();
    getline(cin, nombreDelTrabajo);

    cout << "Ingrese la fecha: " << endl;
    cin.ignore();
    getline(cin, fecha);

    cout << "Ingrese el tipo de trabajo\n1. Aplicado\n2. De investigacion" << endl;
    cin >> tipoTrabajo;

    cout << "Ingrese el ID del autor: " << endl;
    cin >> idPersona;

    autor = buscarPersona(idPersona);
    if(!autor.verificarExistenciaPersona()){
        cout << "No se encontro la persona. Se creara una." << endl;
        crearPersona();
        autor = *listaPersonas.rbegin();
        autor.mostrarPersona();
    }

    cout << "Ingresde el id del jurado uno" << endl;
    cin >> idJuradoUno;

    juradoUno = buscarJurado(idJuradoUno);
    if(!juradoUno.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearJurado();
        juradoUno = *listaJurados.rbegin();
    }
    
    cout << "Ingresde el id del jurado dos" << endl;
    cin >> idJuradoDos;

    juradoDos = buscarJurado(idJuradoDos);
    if(!juradoDos.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearJurado();
        juradoDos = *listaJurados.rbegin();
    }

    cout << "Ingresde el id del director" << endl;
    cin >> idDirector;

    director = buscarPersona(idDirector);
    if(!director.verificarExistenciaPersona()){
        cout << "No se encontro el jurado.Se creara una." << endl;
        crearPersona();
        director = *listaPersonas.rbegin();
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
            codirector = *listaPersonas.rbegin();
        }
    }

    this->listaActas.push_back(Acta(idActa, fecha, autor, nombreDelTrabajo, juradoUno, juradoDos, director, codirector, tipoTrabajo));
}

void Maestria::crearCriterios(){
    int x, idActa;
    list<DetalleCriterio> detalles;
    Acta acta;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;
    acta = buscarActa(idActa);

    for(x = 0; x < 8; x++){
        DetalleCriterio detalleCriterios;
        detalleCriterios.definirCriterio();
        detalles.push_back(detalleCriterios);
    }
    acta.setListaDetalles(detalles);
}

void Maestria::diligenciarCalificaciones(){
    int idActa;
    float nota;
    Acta acta;
    Jurado juradoUno, juradoDos;
    list<DetalleCriterio> detalles;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;
    acta = buscarActa(idActa);

    detalles = acta.getListaDetalles();

    juradoUno = acta.getJuradoUno();
    juradoDos = acta.getJuradoDos();

    for(list<DetalleCriterio>::iterator it = detalles.begin(); it != detalles.end(); it++)
    {
        cout << "Ingrese la nota del jurado uno para el criterio:" << endl;
        it->mostrarCriterio();
        cin >> nota;
        it->setNotaJuradoUno(nota);
        cout << "Ingrese la nota del jurado dos para el mismo criterio:" << endl;
        cin >> nota;
        it->setNotaJuradoDos(nota);
    }
}

void Maestria::ingresarComentarios(){
    int idActa;
    string comentarios;
    Acta acta;
    list<DetalleCriterio> detalles;
    Jurado juradoUno, juradoDos;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;
    acta = buscarActa(idActa);

    detalles = acta.getListaDetalles();

    juradoUno = acta.getJuradoUno();
    juradoDos = acta.getJuradoDos();

    for(list<DetalleCriterio>::iterator it = detalles.begin(); it != detalles.end(); it++)
    {
        cout << "Ingrese los comentarios de los jurados para el criterio:" << endl;
        it->mostrarCriterio();
        getline(cin, comentarios);
    }
}

Acta Maestria::buscarActa(int idActa){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == idActa)
        {
            return *it;
        }
    }
}