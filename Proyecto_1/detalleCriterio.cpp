#include "detalleCriterio.h"

DetalleCriterio::DetalleCriterio(){

}

void DetalleCriterio::crearCriterio(){
    string descripcionCriterio;
    float ponderado;
    cout << "Ingrese la descripcion del ponderado"  << endl;
    getline(cin, descripcionCriterio);
    cout << "Ingrese el porcentaje del ponderado"  << endl;
    cin >> ponderado;
    
    Criterio criterio(descripcionCriterio, ponderado);
    this->criterio = criterio;
}