#include "UndergroundSystem.h"

UndergroundSystem::UndergroundSystem() {}

void UndergroundSystem::checkIn(int id, string stationName, int t) {
    // Cuando el pasajero entra, se guarda en activo
    pasajerosActivos[id] = {stationName, t};
}

void UndergroundSystem::checkOut(int id, string stationName, int t) {
    //Buscar la info de dónde venía el pasajero usando su ID
    CheckInInfo infoEntrada = pasajerosActivos[id];
    
    //Calcular cuánto duró el viaje
    int tiempoViaje = t - infoEntrada.tiempoEntrada;
    
    //"llave" para la ruta
    string nombreRuta = infoEntrada.nombreEstacion + "-" + stationName;
    
    //actualización de estadísticas de esa ruta
    mapaEstadisticas[nombreRuta].sumaTiempos += tiempoViaje;
    mapaEstadisticas[nombreRuta].cantidadViajes += 1;
    
    //se booranal pasajero de los activos porque ya salió del metro
    pasajerosActivos.erase(id);
}

double UndergroundSystem::getAverageTime(string startStation, string endStation) {
    //llave de la ruta que nos piden consultar
    string nombreRuta = startStation + "-" + endStation;
    
    //datos acumulados
    double suma = mapaEstadisticas[nombreRuta].sumaTiempos;
    int cantidad = mapaEstadisticas[nombreRuta].cantidadViajes;
    
    //promedio (Suma/num de viajes)
    return suma / cantidad;
}