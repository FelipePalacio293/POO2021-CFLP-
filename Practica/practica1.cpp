#include <iostream>

class Circulo{
    private:
        float radio;
        float const PI = 3.1416;
    public:
        Circulo(float);
        Circulo();
        float calcularArea();
        float calcularPerimetro();
        float getRadio();
};

Circulo::Circulo(){

}

Circulo::Circulo(float radio){
    this->radio = radio;
}

float Circulo::calcularArea(){
    float area;
    area = PI * (radio * radio);
    std::cout << "El area es:" << area << std::endl;
    return area;
}

float Circulo::calcularPerimetro(){
    float perimetro;
    perimetro = 2 * PI * radio;
    std::cout << "El perimetro es:" << perimetro << std::endl;
    return perimetro;
}

float Circulo::getRadio(){
    return this->radio;
}

int main(){
    int const CAP = 10;
    Circulo miCirculo(3);
    Circulo miCirculoGrande(4);
    miCirculo.calcularArea(); 
    miCirculoGrande.calcularArea();
    Circulo misCirculos[CAP];
    return 0;
}