#include "maestria.h"

Maestria::Maestria(){
}

// Se hace set de unos datos de apoyo para facilitar las pruebas del programa

void Maestria::setDummyData(){
    listaPersonas.push_back(Persona("Santiago Grisales", "santi@gmail.com", 001, 32434, "Estudiante"));
    listaPersonas.push_back(Persona("Gerardo Sarria", "gerar@gmail.com", 002, 43435, "Director"));
    listaPersonas.push_back(Persona("Luisa Rincon", "lufe@gmail.com", 003, 34345, "Codirector"));
    listaJurados.push_back(Jurado("Fabian Ledezma", "Fabian@gmail.com", 004, 34345, "Jurado", 1));
    listaJurados.push_back(Jurado("Juan Orozco", "juan@gmail.com", 005, 465634, "Jurado", 1));
    listaPersonas.push_back(Persona("NA", "NA", 000, 000, "Codirector")); // Se crea un codirector vacío para cuando el acta no tenga codirector
}

// Función que busca y devuelve una persona cuando la encuentra
Persona Maestria::buscarPersona(int id){
    for(list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++){
        if(it->getId() == id){
            return *it;
        }
    }
    Persona persona;
    persona.setId(0); // Cuando la persona no es encontrada, se devuelve una variable de tipo persona con el id en 0
    return persona;
}

// Función que busca y devuelve un jurado cuando la encuentra
Jurado Maestria::buscarJurado(int id){
    for(list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++){
        if(it->getId() == id){
            return *it;
        }
    }
    Jurado jurado;
    jurado.setId(0); // Cuando el jurado no es encontrado, se devuelve una variable de tipo Jurado con el id en 0
    return jurado;
}

// Función que crea una persona
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

    // Se envían los datos al constructor y se agrega a la lista.
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

// Función que crea un acta
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
    // Se verifica si el id de la persona es 0, en caso de serlo quiere decir que la persona no existe
    // y se procede a crearla.
    if(!autor.verificarExistenciaPersona()){
        cout << "No se encontro la persona. Se creara una." << endl;
        crearPersona();
        autor = *listaPersonas.rbegin(); // Rbegin devuelve un apuntador al último elemento de la lista
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
        // En caso de que no exista codirector se usa el codirector NA creado al inicio del programa
        idCodirector = 0;
        codirector = buscarPersona(idCodirector);
    }
    // Se crea el objeto con el constructor y se agrega en la lista de las actas
    this->listaActas.push_back(Acta(idActa, fecha, autor, nombreDelTrabajo, juradoUno, juradoDos, director, codirector, tipoTrabajo));
}

// Función que devuelve 0 cuando encuentra el acta y 1 cuando no la encuentra
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

    if(verificarExistenciaActa(idActa)){ // Siempre se verifica que el acta exista, para que el programa no de errores.
        cout << "El acta no existe" << endl;
        return;
    }
    // Se llama al método llenar criterios cuando encuentra el acta
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
    it->ingresarCaLificaciones(); // Se llama el método ingresar calificaciones cuando encuentra el acta
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
    it->ingresarComentarios(); // Se llama el método ingresar comentarios cuando encuentra el acta
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
            return it; // Función que devuelve un apuntador al acta cuando la encuentra
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
    it->mostrarDetalleCriterio(); // Se llaman al método de acta que se llama mostrarDetalleCriterio

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
    it->sacarNotaFinalActa(); // Se llama al método de acta que se llama sacar nota final
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
    it->cerrarActa(); // Se llama al método de acta que se llama cerrar acta
}

void Maestria::mostrarTodasLasActas(){
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        it->mostrarDatos(); // Se hace un ciclo recorriendo toda la lista de actas y se imprimen todas
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
        if(it->getEstadoActa() == estadoUsuario) // Se buscan solo las actas que tengan el estado deseado por el usuario y se imprimen.
            it->mostrarDatos();
    }
}

void Maestria::mostrarTrabajosPorTipo(TipoDeTrabajo tipo){
    int cont = 0;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){
        if(it->getTipoDeTrabajo() == tipo){ // Se buscan las actas del tipo que se define por parámetro
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
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++){ // Se buscan todas las actas con estado pendiente o rechazado (esto se maneja con un enum dentro de la clase acta)
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
    listaActas.erase(it); // Se utiliza el método erase de la las lists de C++ para borrar el elemento.

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