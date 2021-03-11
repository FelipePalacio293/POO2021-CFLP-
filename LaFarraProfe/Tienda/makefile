all: compilar
compilar: producto cliente DetalleVenta ventas tienda menu main
		g++ -o a producto.o cliente.o DetalleVenta.o ventas.o tienda.o menu.o main.o
cliente: cliente.cpp cliente.h
		g++ -c cliente.cpp
producto: producto.cpp producto.h
		g++ -c producto.cpp
DetalleVenta: DetalleVenta.cpp DetalleVenta.h
		g++ -c DetalleVenta.cpp
ventas: ventas.cpp ventas.h
		g++ -c ventas.cpp
tienda: tienda.cpp tienda.h
		g++ -c tienda.cpp
menu: menu.cpp menu.h
		g++ -c menu.cpp
main: main.cpp menu.h tienda.h producto.h 
	  	g++ -c main.cpp