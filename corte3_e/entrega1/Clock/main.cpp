#include <iostream>
#include "Clock.h"

using namespace std;

int main() {
    cout << "--- Prueba de Clock ---" << endl;

    //Crear reloj y mostrar hora
    Clock reloj1(10, 30);
    cout << "Reloj inicial: " << reloj1.toString() << endl;

    //Sumar minutos, pasando de un día a otro
    Clock reloj2 = reloj1.plus(1500); 
    cout << "Despues de sumar 1500 min: " << reloj2.toString() << endl;

    //Restar minutos (tiempo negativo)
    Clock reloj3 = reloj1.minus(120); 
    cout << "Despues de restar 120 min: " << reloj3.toString() << endl;

    //Comparar dos relojes
    Clock c1(15, 45);
    Clock c2(15, 45);
    if (c1 == c2) {
        cout << "Los relojes c1 y c2 son iguales." << endl;
    }

    return 0;
}
