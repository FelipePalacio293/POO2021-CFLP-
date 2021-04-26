#include <iostream>
#include <conio.h>
#include "circulo.h"
#include "rectangulo.h"
#include "triangulo.h"
const int CAP = 10;
using namespace std;

void mostrarFiguras(Circulo circulos[CAP], Rectangulo rectangulos[CAP], Triangulo triangulos[CAP], int contadorCirculos, int contadorRectangulos, int contadorTriangulos)
{
	int i, j, k;
	
	cout << "------------Circulos--------------\n";
	for( i = 0; i < contadorCirculos; i++ )
	{
		cout << "Circulo numero " << i+1<<".\n";
		cout << "Radio: " << circulos[i].getRadio() << " metros.\n";
		circulos[i].calcularAreaCirculo();
		circulos[i].calcularPerimetroCirculo();
		cout << "\n";
	};
	
	cout << "----------Rectangulos-------------\n";
	
	for( j = 0; j < contadorRectangulos; j++ )
	{
		cout << "Rectangulo numero " << j+1<<".\n";
		cout << "Ancho: " << rectangulos[j].getAncho() << " metros.\n";
		cout << "Largo: " << rectangulos[j].getLargo() << " metros.\n";
		rectangulos[j].calcularAreaRectangulo();
		rectangulos[j].calcularPerimetroRectangulo();
		cout << "\n";
	};
	
	cout << "----------Triangulos-------------\n";
	
	for( k = 0; k < contadorTriangulos; k++ )
	{
		cout << "Triangulo numero " << k+1<<".\n";
		cout << "Base: " << triangulos[k].getBase() << " metros.\n";
		cout << "Altura: " << triangulos[k].getAltura() << " metros.\n";
		triangulos[k].calcularAreaTriangulo();
		triangulos[k].calcularPerimetroTriangulo();
		cout << "\n";
	};
}

void crearTriangulo(Triangulo triangulos[CAP], int contadorTriangulos)
{
	int base, altura;
	cout << "Ingrese la base del triangulo " << contadorTriangulos + 1 << " en metros: ";
	cin >> base; 
	cout << "Ingrese la altura del triangulo " << contadorTriangulos + 1 << " en metros: ";
	cin >> altura;
	triangulos[contadorTriangulos].setBase(base);
	triangulos[contadorTriangulos].setAltura(altura);
}

void crearRectangulo(Rectangulo rectangulos[CAP], int contadorRectangulos)
{
	int ancho, largo;
	cout << "Ingrese el ancho del rectangulo " << contadorRectangulos + 1 << " en metros: ";
	cin >> ancho;
	cout << "Ingrese el largo del rectangulo " << contadorRectangulos + 1 << " en metros: ";
	cin >> largo;
	rectangulos[contadorRectangulos].setAncho(ancho);
	rectangulos[contadorRectangulos].setLargo(largo);
}

void crearCirculo(Circulo circulos[CAP], int contadorCirculos)
{
	int radio;
	cout << "Ingrese el radio del circulo " << contadorCirculos + 1 << " en metros: ";
	cin >> radio;
	circulos[contadorCirculos].setRadio(radio);
}

int main()
{
	/*Circulo primerCirculo ( 3 );
	primerCirculo.calcularArea();
	Circulo segundoCirculo ( 5 );
	segundoCirculo.calcularArea(); Primer Punto */
	Circulo circulos[CAP];
	Rectangulo rectangulos[CAP];
	Triangulo triangulos[CAP];
	int opcion = 0, contadorCirculos = 0, contadorRectangulos = 0, contadorTriangulos = 0;
	cout << "Bienvenido al menu del programa.\n";
	do
	{
		cout << "1.Crear circulo.\n2.Crear rectangulo.\n3.Crear triangulo equilatero.\n4.Mostrar figuras.\n5.Salir.\nOpcion: ";
		cin >> opcion;
		switch(opcion)
		{
			case 1:
				if(contadorCirculos < CAP)
				{
					cout << "Ha elegido crear circulo.\n";
					crearCirculo(circulos, contadorCirculos);
					cout << "El circulo ha sido creado.\n";
					contadorCirculos++;
					break;
				}
				else
				{
					cout << "No hay espacio en el arreglo de circulos.\n";
					break;
				}
			case 2:
				if(contadorRectangulos < CAP)
				{
					cout << "Ha elegido crear rectangulo.\n";
					crearRectangulo(rectangulos, contadorRectangulos);
					cout << "El rectangulo ha sido creado.\n";
					contadorRectangulos++;
					break;
				}
				else
				{
					cout << "No hay espacio en el arreglo rectangulos.\n";
					break;
				}
			case 3:
				if(contadorTriangulos < CAP)
				{
					cout << "Ha elegido crear triangulo equilatero.\n";
					crearTriangulo(triangulos, contadorTriangulos);
					contadorTriangulos++;
					break;
				}
				else
				{
					cout << "No hay espacio en el arreglo de triangulos equilateros.\n";
					break;
				}
			case 4:
				cout << "Ha elegido mostrar las figuras.\n";
				mostrarFiguras(circulos, rectangulos, triangulos, contadorCirculos, contadorRectangulos, contadorTriangulos);
				break;
			case 5:
				cout << "Gracias por usar nuestro programa.\n";
		}
	}while(opcion != 5);
	return 0;
}
