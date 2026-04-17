#ifndef UNDERGROUND_SYSTEM_H
#define UNDERGROUND_SYSTEM_H

#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
private:
    //guardar los datos de cuando alguien entra a una estación
    struct CheckInInfo {
        string nombreEstacion;
        int tiempoEntrada;
    };

    //acumular los tiempos de viaje entre dos estaciones
    struct EstadisticasRuta {
        double sumaTiempos;
        int cantidadViajes;
    };

    // Mapa para saber quién está viajando (ID y datos de entrada)
    unordered_map<int, CheckInInfo> pasajerosActivos;

    // Mapa para las estadísticas (ruta. Suma y cantidad de viajes)
    unordered_map<string, EstadisticasRuta> mapaEstadisticas;

public:
    UndergroundSystem(); //constructor
    void checkIn(int id, string stationName, int t);
    void checkOut(int id, string stationName, int t);
    double getAverageTime(string startStation, string endStation);
};

#endif