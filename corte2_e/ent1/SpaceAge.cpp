#include <iostream>
#include <iomanip> //limitar los decimales al mostrar el resultado

using namespace std;

int main() {
    const double SEGUNDOS_ANIO_TIERRA = 31557600.0;
    
    long long segundosVividos; //long long: número de segundos puede ser muyyy grande
    double edadTierra;

    cout << "Ingrese su edad en segundos: ";
    cin >> segundosVividos;

    edadTierra = segundosVividos / SEGUNDOS_ANIO_TIERRA;

    //Factores orbitales
    double factorMercurio = 0.2408467;
    double factorVenus = 0.61519726;
    double factorMarte = 1.8808158;

    //Edad en Mercurio como ejemplo
    double edadMercurio = edadTierra / factorMercurio;

    cout << fixed << setprecision(2); 
    cout << "Edad en la Tierra: " << edadTierra << " años." << endl;
    cout << "Edad en Mercurio es: " << edadMercurio << " ." << endl;

    return 0;
}