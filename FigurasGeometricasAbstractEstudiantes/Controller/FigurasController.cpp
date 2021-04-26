#include "../Controller/FigurasController.h"

// Inicializacion constante estatica para elemento compartido
const int FigurasController::MAX_ITEMS = 10;

void FigurasController::agregarRectangulo(const float largo, const float ancho)
{
    cout << "Agrego rectangulo" << endl;
    FiguraGeometrica *pRectTemp = new Rectangulo(largo, ancho);
    listaFiguras.push_back(pRectTemp);
}

void FigurasController::agregarCuadrado(const float lado){
    cout << "Agrego cuadrado" << endl;
    FiguraGeometrica *pCuadTemp = new Cuadrado(lado);
    listaFiguras.push_back(pCuadTemp);
}

void FigurasController::agregarTriangulo(const float base, const float altura){
    cout << "Agrego cuadrado" << endl;
    FiguraGeometrica *pTriagTemp = new Triangulo(base, altura);
    listaFiguras.push_back(pTriagTemp);
}

void FigurasController::agregarCirculo(const float radio)
{
    cout << "Agrego cuadrado" << endl;
    FiguraGeometrica *pCircTemp = new Circulo(radio);
    listaFiguras.push_back(pCircTemp);
}

list<Rectangulo> &FigurasController::getListaRectangulo()
{
    // Creo la  referencia
    list<Rectangulo> &lista = listaRectangulo;
    return lista;
}

Rectangulo &FigurasController::encontrarMayorAncho()
{
    bool isFirst = true;
    int mayorAncho = 0;
    Rectangulo *pRectanguloMayor = NULL;
    for (list<Rectangulo>::iterator it = listaRectangulo.begin(); it != listaRectangulo.end(); ++it)
    {
        if (isFirst)
        {
            // Se inicializa el mayor ancho con el primer elemento
            int mayorAncho = listaRectangulo.begin()->getAncho();
            isFirst = false;
            pRectanguloMayor = &(*it); // It es un apuntador, para acceder al rectangulo se tiene que acceder al contenido
        }
        else
        {
            if (it->getAncho() > pRectanguloMayor->getAncho())
            {
                // Actaulizar el mayor
                pRectanguloMayor = &(*it);
            }
        }
    }
    // Se obtien el contenido del apuntador para luego retorar la referencia
    // a fin de facilitar el manejo de los objetos posteriormente
    return *pRectanguloMayor;
}

list<FiguraGeometrica *> &FigurasController::getListaFiguras(){
    return this-> listaFiguras;
}