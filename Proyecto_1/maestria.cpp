#include "maestria.h"

Maestria::Maestria(){
}

void Maestria::setDummyData(){
    listaPersonas.push_back(Persona("Santiago Grisales", "santi@gmail.com", 001, 32434, "Estudiante"));
    listaPersonas.push_back(Persona("Gerardo Sarria", "gerar@gmail.com", 002, 43435, "Director"));
    listaPersonas.push_back(Persona("Luisa Rincon", "lufe@gmail.com", 003, 34345, "Codirector"));
    listaJurados.push_back(Jurado("Fabian Ledezma", "Fabian@gmail.com", 004, 34345, "Jurado", 1));
    listaJurados.push_back(Jurado("Juan Orozco", "juan@gmail.com", 005, 465634, "Jurado", 1));
    listaPersonas.push_back(Persona("NA", "NA", 000, 000, "Codirector"));
}

Persona Maestria::buscarPersona(int id){
    for(list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++){
        if(it->getId() == id){
            return *it;
        }
    }
    Persona persona;
    persona.setId(0);
    return persona;
}

Jurado Maestria::buscarJurado(int id){
    for(list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++){
        if(it->getId() == id){
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
    else{
        idCodirector = 0;
        codirector = buscarPersona(idCodirector);
    }
    this->listaActas.push_back(Acta(idActa, fecha, autor, nombreDelTrabajo, juradoUno, juradoDos, director, codirector, tipoTrabajo));
}

int Maestria::verificarExistenciaActa(int idActa){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getNumero() == idActa){
            return 0;
        }
    }
    return 1;
}

void Maestria::crearCriterios() {
    int x, idActa;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->llenarCriterios();
}

void Maestria::diligenciarCalificaciones(){
    int idActa;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "El acta no existe" << endl;
        return;
    }
    it = obtenerActa(idActa);

    if(!it->getPuedeCalificarse()){
        cout << "No se han creado los criterios de este acta" << endl;
        return;
    }
    it->ingresarCaLificaciones();
}

void Maestria::diligenciarComentarios(){
    int idActa;
    string comentarios;
    list<DetalleCriterio> detalles;
    Jurado juradoUno, juradoDos;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->ingresarComentarios();
}

void Maestria::actualizarActa(int id){
    return;
}

Acta Maestria::buscarActa(int idActa){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getNumero() == idActa){
            return *it;
        }
    }
}

list<Acta>::iterator Maestria::obtenerActa(int idActa){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getNumero() == idActa){
            return it;
        }
    }
}

void Maestria::mostrarTodosLosCriterios(){
    int idActa;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->mostrarDetalleCriterio();

}
void Maestria::obtenerNotaFinalDeUnActa(){
    int idActa;
    list<Acta>::iterator it;
    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->sacarNotaFinalActa();
}

void Maestria::cerrarUnActa(){
    int idActa;
    list<Acta>::iterator it;
    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->cerrarActa();
}

void Maestria::mostrarTodasLasActas(){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        it->mostrarDatos();
    }
}

void Maestria::listarActasPorEstado(){
    int estado;
    EstadoActa estadoUsuario;

    cout << "Ingrese el tipo de acta que desea consultar:\n1.Abiertas\n2.Cerradas" << endl;
    cin >> estado;
    if(estado == 1){
        estadoUsuario = abierto;
    }
    else{
        estadoUsuario = cerrado;
    }
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getEstadoActa() == estadoUsuario)
            it->mostrarDatos();
    }
}

void Maestria::mostrarTrabajosPorTipo(TipoDeTrabajo tipo){
    int cont = 0;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getTipoDeTrabajo() == tipo){
            it->mostrarDatos();
            cont++;
        }
    }
    cout << "La cantidad de trabajos aplicados fueron: " << cont << endl;
}

void Maestria::mostrarTrabajosPorProfesor(){
    int idProfesor, contProfesor;
    cout << "Ingrese el ID del profesor que desea buscar:" << endl;
    cin >> idProfesor;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        contProfesor += it->buscarProfesorDado(idProfesor);
    }
}

void Maestria::mostrarTrabajoPorJurado(){
    int idJurado;
    cout << "Ingrese el ID del profesor que desea buscar:" << endl;
    cin >> idJurado;
    cout << "La persona ha sido jurado de los siguientes proyectos:" << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        it->mostrarTrabajoJurado(idJurado);
    }
}

void Maestria::mostrarTodosLosJurados(){
    for(list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++){
        it->mostrarJurado();
    }
}

void Maestria::mostrarActasPorEstadoCalificacion(){
    cout << "Se imprimiran las actas pendientes y rechazadas" << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getEstadoCalificacion() == rechazado || it->getEstadoCalificacion() == pendiente){
            it->mostrarDatos();
        }
    }
}

void Maestria::consultarJuradosPorTipo(TipoJurado tipo){
    for(list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++){
        if(it->getTipoJurado() == tipo)
            it->mostrarJurado();
    }
}

void Maestria::eliminarActa(){
    int idActa;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    listaActas.erase(it);

}

void Maestria::generarArchivoDeTexto(){
    int idActa;
    list<Acta>::iterator it;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    it = obtenerActa(idActa);
    it->guardarInformacionArchivoTexto();
}

void Maestria::verificarComentariosAdicionales() {
    int idActa;
    list<Acta>::iterator it;
    string comentarios;

    cout << "Ingrese el ID del acta:" << endl;
    cin >> idActa;

    if(verificarExistenciaActa(idActa)){
        cout << "==========================" << endl;
        cout << "El acta no existe" << endl;
        return;
    }

    cout << "Ingrese los comentarios adicionales: " << endl;
    getline(cin, comentarios);

    it = obtenerActa(idActa);
    it->setComentariosAdicionales(comentarios);
}
