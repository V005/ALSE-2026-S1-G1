#include <iostream>
#include "Meetup.h"

using namespace std;

int main() {
    cout << "--- Buscador de Fechas de Meetup ---" << endl;

    //Ejemplos: 10 Saturday de Agosto 1953
    Meetup m1(8, 1953);
    cout << "Teenth Saturday de Agosto 1953: " << m1.day("Saturday", "teenth") << " (Esperado: 15)" << endl;

    //último jueves de Noviembre 2022
    Meetup m2(11, 2022);
    cout << "Last Thursday de Noviembre 2022: " << m2.day("Thursday", "last") << " (Esperado: 24)" << endl;

    //primer lunes de Enero 2018
    Meetup m3(1, 2018);
    cout << "First Monday de Enero 2018: " << m3.day("Monday", "first") << " (Esperado: 1)" << endl;

    return 0;
}