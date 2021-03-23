#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    string nombreArchivo = "MontanaRusa";
    nombreArchivo += ".txt";
    file.open(nombreArchivo.c_str(), ios::out);
    file << "  ---  Acta de evaluacion de trabajo de grado  ---  " << endl;
    file.close();
    return 0;
}