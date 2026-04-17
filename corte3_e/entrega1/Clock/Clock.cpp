#include "Clock.h"
#include <iomanip>
#include <sstream>

// 1 día = 1440 minutos
const int MINUTOS_DIA = 1440;

void Clock::normalizar() {
    //minutos en el rango de un dia
    total_minutos %= MINUTOS_DIA;
    
    //si el resultado es negativo se suma un día
    if (total_minutos < 0) {
        total_minutos += MINUTOS_DIA;
    }
}

Clock::Clock(int hours, int minutes) {
    total_minutos = (hours * 60) + minutes;
    normalizar();
}

Clock Clock::plus(int minutesToAdd) {
    return Clock(0, total_minutos + minutesToAdd);
}

Clock Clock::minus(int minutesToSubtract) {
    return Clock(0, total_minutos - minutesToSubtract);
}

string Clock::toString() const {
    int h = total_minutos / 60;
    int m = total_minutos % 60;
    
    stringstream ss;
    //estos comandos sirven para que se vea "08:05" en vez de "8:5" es decir el formato hora
    ss << setfill('0') << setw(2) << h << ":" 
       << setfill('0') << setw(2) << m;
    return ss.str();
}

bool Clock::operator==(const Clock& other) const {
    return this->total_minutos == other.total_minutos;
}