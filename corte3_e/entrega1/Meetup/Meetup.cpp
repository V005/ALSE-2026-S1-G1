#include "Meetup.h"

Meetup::Meetup(int month, int year) : _month(month), _year(year) {}

bool Meetup::esBisiesto(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Meetup::diasEnMes(int m, int y) {
    if (m == 2) return esBisiesto(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

//0 para domingo, 1 para lunes y así
int Meetup::diaDeLaSemana(int d, int m, int y) {
    if (m < 3) { m += 12; y--; }
    int k = y % 100;
    int j = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
    //para que 0 sea Domingo
    return (h + 5) % 7; 
}

int Meetup::stringADiaSemana(string w) {
    if (w == "Monday") return 1;
    if (w == "Tuesday") return 2;
    if (w == "Wednesday") return 3;
    if (w == "Thursday") return 4;
    if (w == "Friday") return 5;
    if (w == "Saturday") return 6;
    return 0; //domingo
}

int Meetup::day(string weekday, string week) {
    int objetivo = stringADiaSemana(weekday);
    int inicio, fin;

    //rango de búsqueda según la semana pedida
    if (week == "first") { inicio = 1; fin = 7; }
    else if (week == "second") { inicio = 8; fin = 14; }
    else if (week == "third") { inicio = 15; fin = 21; }
    else if (week == "fourth") { inicio = 22; fin = 28; }
    else if (week == "teenth") { inicio = 13; fin = 19; }
    else if (week == "last") { 
        fin = diasEnMes(_month, _year);
        inicio = fin - 6;
    }

    //día que coincide
    for (int d = inicio; d <= fin; d++) {
        if (diaDeLaSemana(d, _month, _year) == objetivo) {
            return d;
        }
    }
    return -1;
}