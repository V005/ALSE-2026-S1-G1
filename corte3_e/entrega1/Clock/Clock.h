#ifndef CLOCK_H
#define CLOCK_H

#include <string>

using namespace std;

class Clock {
private:
    int total_minutos; //se guarda todo en minutos para facilitar los calculos

    //normalizar el time (mantenerlo entre 0 y 1439 minutos)
    void normalizar();

public:
    //recibe horas y minutos
    Clock(int hours, int minutes);

    //sumar y restar
    Clock plus(int minutesToAdd);
    Clock minus(int minutesToSubtract);

    //mostrar la hora en formato "HH:MM"
    string toString() const;

    //Sobrecarga del operador de igualdad para comparar dos relojes
    bool operator==(const Clock& other) const;
};

#endif