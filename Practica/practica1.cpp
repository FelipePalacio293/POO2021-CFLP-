#include <iostream>
const int CAP = 10;

class Circulo{
    private:
        float radio;
        float const PI = 3.1416;
    public:
        Circulo(float);
        Circulo();
        float calcularAreaCirculo();
        float calcularPerimetroCirculo();
        float getRadio();
        void setRadio(float);
};

class Rectangulo{
    private:
        float largo, ancho;
    public:
        Rectangulo();
        Rectangulo(float, float);
        void calcularPerimetroRectangulo();
        void calcularAreaRectangulo();
        float getLargo();
        float getAncho();
        void setLargo(float);
        void setAncho(float);
};

Rectangulo::Rectangulo(){
    this->largo = 0;
    this->ancho = 0;
}

Rectangulo::Rectangulo(float largo, float ancho){
    this->largo = largo;
    this->ancho = ancho;
}

void Rectangulo::calcularPerimetroRectangulo(){
    float perimetro;
    perimetro = 2 * largo + 2 * ancho;
    std::cout << "El perimetro es:" << perimetro << std::endl;
}

void Rectangulo::calcularAreaRectangulo(){
    float area;
    area = largo * ancho;
    std::cout << "El area es:" << area << std::endl;
}

float Rectangulo::getLargo(){
    return this->largo;
}

float Rectangulo::getAncho(){
    return this->ancho;
}

void Rectangulo::setLargo(float largo){
    this->largo = largo;
}

void Rectangulo::setAncho(float ancho){
    this->ancho = ancho;
}

Circulo::Circulo(){
    this->radio = 0;
}

Circulo::Circulo(float radio){
    this->radio = radio;
}

float Circulo::calcularAreaCirculo(){
    float area;
    area = PI * (radio * radio);
    std::cout << "El area es:" << area << std::endl;
    return area;
}

float Circulo::calcularPerimetroCirculo(){
    float perimetro;
    perimetro = 2 * PI * radio;
    std::cout << "El perimetro es:" << perimetro << std::endl;
    return perimetro;
}

void Circulo::setRadio(float radio){
    this->radio = radio;
}

float Circulo::getRadio(){
    return this->radio;
}

void crearCirculo(int posicion, Circulo circulos[CAP]){
    float radio;
    std::cout << "Ingrese el radio del circulo ";
    std::cin >> radio;
    circulos[posicion].setRadio(radio);
}

void crearRectangulo(int posicion, Rectangulo rectangulos[CAP]){
    float largo, ancho;
    std::cout << "Ingrese el largo del rectangulo ";
    std::cin >> largo;
    std::cout << "Ingrese el ancho del rectangulo ";
    std::cin >> ancho;
    rectangulos[posicion].setLargo(largo);
    rectangulos[posicion].setAncho(ancho);
}

int main(){
    Circulo circulos[CAP];
    Rectangulo rectangulos[CAP];
    int contRectangulos = 0, contCirculos = 0, opcion;
    do{
        std::cout << "Ingrese la figura que desea crear:\n1. Circulo\n2. Rectangulo\n0. Salir\n";
        std::cin >> opcion;
        if(opcion == 1){
            if(contCirculos < CAP){
                crearCirculo(contCirculos, circulos);
                contCirculos++;
            }
            else{
                std::cout << "No hay mas espacio para crear circulos\n" << std::endl;
            }
        }
        else if(opcion == 2){
            if(contRectangulos < CAP){
                crearRectangulo(contRectangulos, rectangulos);
                contRectangulos++;
            }
            else{
                std::cout << "No hay mas espacio para crear rectangulos\n" << std::endl;
            }
        }
        if( contRectangulos >= CAP && contCirculos >= CAP ){
            std::cout << "No hay mas espacio para crear figuras\n" << std::endl;
            opcion = 0;
        }
    } while(opcion != 0);

    return 0;
}