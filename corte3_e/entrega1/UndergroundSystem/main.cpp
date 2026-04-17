#include <iostream>
#include <iomanip> // promedio con decimales organizados
#include "UndergroundSystem.h"

using namespace std;

int main() {
    UndergroundSystem* metro = new UndergroundSystem();

    //EJEMPLOOO
    cout << "--- Iniciando simulacion del Metro ---" << endl;
    
    metro->checkIn(45, "Leyton", 3);
    metro->checkIn(32, "Paradise", 8);
    metro->checkOut(45, "Waterloo", 15); //viaje dura 12
    
    cout << "Promedio Leyton a Waterloo: " << metro->getAverageTime("Leyton", "Waterloo") << endl;

    metro->checkIn(27, "Leyton", 10);
    metro->checkOut(27, "Waterloo", 20); //viaje dura 10
    

    cout << "Nuevo promedio Leyton a Waterloo: " << metro->getAverageTime("Leyton", "Waterloo") << endl;

    delete metro; //liberar memory
    return 0;
}