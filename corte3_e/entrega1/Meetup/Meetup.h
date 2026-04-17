#ifndef MEETUP_H
#define MEETUP_H

#include <string>

using namespace std;

class Meetup {
public:
    Meetup(int month, int year);
    
    //encontrar el día
    int day(string weekday, string week);

private:
    int _month;
    int _year;

    // Funciones auxiliares como el año bisiesto 
    bool esBisiesto(int y);
    int diasEnMes(int m, int y);
    int diaDeLaSemana(int d, int m, int y); // 0=Dom, 1=Lun...
    int stringADiaSemana(string w);
};

#endif