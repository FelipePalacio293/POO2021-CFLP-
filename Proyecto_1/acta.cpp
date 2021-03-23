#include "acta.h"

Acta::Acta(){

}

// Constructor para la creación de un acta
Acta::Acta(int numero, string fecha, Persona autor, string nombreTrabajo, Jurado juradoUno, Jurado juradoDos, Persona director, Persona codirector, int tipoDeTrabajo){
    this->numero = numero;
    this->fecha = fecha;
    this->autor = autor;
    this->nombreTrabajo = nombreTrabajo;
    this->juradoUno = juradoUno;
    this->juradoDos = juradoDos;
    this->director = director;
    this->codirector = codirector;
    this->numeroDeCriterios = 8;
    this->estadoActa = abierto;
    this->estadoCalificacion = pendiente;
    if(tipoDeTrabajo == 1)
        this->tipoTrabajo = aplicado;
    else
        this->tipoTrabajo = investigacion;
    this->puedeCalificarse = 0;
    this->notaFinal = 0;
    this->tieneCalificaciones = 0;
}

void Acta::calificarActa(){
    int x;
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }
    for(x = 0; x < this->numeroDeCriterios; x++){
        detallesCriterios.push_back(DetalleCriterio());
    }
}

int Acta::getNumero(){
    return this->numero;
}

Jurado Acta::getJuradoUno(){
    return this->juradoUno;
}

Jurado Acta::getJuradoDos(){
    return this->juradoDos;
}

void Acta::setListaDetalles(list<DetalleCriterio> detallesCriterios){
    this->detallesCriterios = detallesCriterios;
}

list<DetalleCriterio> Acta::getListaDetalles(){
    return this->detallesCriterios;
}

void Acta::ingresarComentarios(){
    string comentarios;
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }
    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++){
        cout << "Ingrese los comentarios de los jurados para el criterio:" << endl;
        it->mostrarCriterio();
        getline(cin, comentarios);
    }
}

void Acta::ingresarCaLificaciones(){
    float nota;
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }

    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++){
        cout << "Ingrese la nota del jurado uno para el criterio:" << endl;
        it->mostrarCriterio();
        cin >> nota;
        it->setNotaJuradoUno(nota);
        cout << "Ingrese la nota del jurado dos para el mismo criterio:" << endl;
        cin >> nota;
        it->setNotaJuradoDos(nota);
    }
    this->puedeCalificarse = 1;
}

// Función que se encarga de crear los criterios del acta, haciendo uso de una variable detalle criterio
// de forma temporal.
void Acta::llenarCriterios(){
    int x;
    DetalleCriterio detalleCriterio;
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }
    for(x = 0; x < 8; x++){
        detalleCriterio.definirCriterio(); // Se llama al metodo de detalle criterio que permite llenar los criterios
        this->detallesCriterios.push_back(detalleCriterio);
    }
    this->tieneCalificaciones = 1;
}

void Acta::mostrarDetalleCriterio(){
    for(list<DetalleCriterio>::iterator it = detallesCriterios.begin(); it != detallesCriterios.end(); it++){
        it->mostrarCriterio();
    }
}

void Acta::definirEstadoCalificacion(){
    if(this->notaFinal < 3.5)
        this->estadoCalificacion = rechazado;
    else
        this->estadoCalificacion = aprobado;
}

// Se define la nota final del acta, sacando también así, una nota promedio y una nota ponderada.
void Acta::sacarNotaFinalActa(){
    if(this->estadoActa == cerrado){
        cout << "Este acta ya se encuentra cerrada." << endl;
        return;
    }
    if(this->puedeCalificarse == 0){
        cout << "Esta acta aun no esta calificada por los jurados. Califiquela primero" << endl;
        return;
    }
    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++) {
        it->calcularNotaPonderado();
        it->calcularNotaPromedio();
    }
    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != this->detallesCriterios.end(); it++) {
        this->notaFinal += it->getNotaPromedio();
    }
    cout << this->notaFinal << endl;
    definirEstadoCalificacion();
}

void Acta::cerrarActa(){
    this->estadoActa = cerrado;
}

void Acta::mostrarDatos(){
    cout << "ID: " << this->numero << endl;
    cout << "Fecha: " << this->fecha << endl;
    cout << "Autor: " << autor.getNombre() << endl;
    cout << "Estado del acta: " << this->estadoActa << endl;
    cout << "Nota: " << this->notaFinal << endl;
}

EstadoActa Acta::getEstadoActa(){
    return this->estadoActa;
}

TipoDeTrabajo Acta::getTipoDeTrabajo(){
    return this->tipoTrabajo;
}

int Acta::buscarProfesorDado(int idProfesor){
    if(this->director.getId() == idProfesor || this->codirector.getId() == idProfesor || this->juradoUno.getId() == idProfesor || this->juradoUno.getId() == idProfesor){
        cout << "El profesor ha participado en el acta:" << endl;
        mostrarDatos();
        return 1;
    }
    return 0;
}

void Acta::mostrarTrabajoJurado(int idJurado){
    if(idJurado == juradoUno.getId() || idJurado == juradoDos.getId())
        mostrarDatos();
}

EstadoCalificacion Acta::getEstadoCalificacion(){
    return this->estadoCalificacion;
}

// Función que se encarga de generar un archivo de texto con los datos del acta que ha solicitado
// el usuario
void Acta::guardarInformacionArchivoTexto(){
    ofstream file;
    string nombreArchivo = this->nombreTrabajo;
    nombreArchivo += ".txt";
    file.open(nombreArchivo.c_str(), ios::out);  // EL nombre del archivo es el mismo nombre del proyecto
    file << "  ---  Acta de evaluacion de trabajo de grado  ---  " << endl;
    file << "Trabajo de grado denominado: " << this->nombreTrabajo << endl;
    file << "Autor: " << this->autor.getNombre() << " ID:  " << this->autor.getId() << endl;
    file << "Periodo: " << this->fecha << endl;
    file << "Enfasis en: Sistemas y computacion\n" << endl;
    string tipo;
    if(this->tipoTrabajo == 0)
        file << "Modalidad: Aplicado\n" << endl;
    else
        file << "Modalidad: Investigacion\n" << endl;
    file << "Jurado 1: " << this->juradoUno.getNombre() << "\n" << endl;
    file << "Jurado 2: " << this->juradoDos.getNombre() << "\n\n\n" << endl;
    file << "En atención al desarrollo de este Trabajo de Grado y al documento y sustentación que presentó el(la) autor(a),\n los  Jurados  damos  las  siguientes  calificaciones  parciales  y  observaciones  (los  criterios  a  evaluar\n  y  sus ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo\n de Grado de Maestría)\n\n\n" << endl;
    int cont = 1;
    for(list<DetalleCriterio>::iterator it = this->detallesCriterios.begin(); it != detallesCriterios.end(); it++){
        file << cont << ". " << it->getDescripcionCriterio() << ":\n\n" << endl;
        file << "Calificacion parcial: " << it->getNotaPromedio() << "                    Ponderacion: " << it->getPonderadoCriterio() << "%\n\n" << endl;
        file << it->getComentario() << "\n\n" << endl;
        file << "---------------------------------------------------------------------" << endl;
        cont++;
    }

    file << "Como  resultado  de  estas  calificaciones  parciales\n  y  sus  ponderaciones,  la  calificación  del Trabajo  deGrado es: "<< this->notaFinal << endl;

    file.close();
}

int Acta::getPuedeCalificarse() {
    return this->tieneCalificaciones;
}

void Acta::setComentariosAdicionales(string comentariosAdicionales){
    this->comentariosAdicionales = comentariosAdicionales;
}