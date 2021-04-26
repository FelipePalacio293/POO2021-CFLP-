all: compilar
compilar: circulo triangulo rectangulo figuraGeometrica main
	g++ -o Salida circulo.o triangulo.o rectangulo.o figuraGeometrica.o main.o
figuraGeometrica: figuraGeometrica.cpp figuraGeometrica.h
	g++ -c figuraGeometrica.cpp
circulo: circulo.cpp circulo.h
	g++ -c circulo.cpp
rectangulo: rectangulo.cpp rectangulo.h
	g++ -c rectangulo.cpp
triangulo: triangulo.cpp triangulo.h
	g++ -c triangulo.cpp
main: main.cpp acta.h criterio.h detalleActa.h persona.h universidad.h
	g++ -c main.cpp