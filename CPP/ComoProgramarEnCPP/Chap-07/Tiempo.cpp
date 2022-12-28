#include<iostream>
#include<iomanip>
#include<stdexcept>
#include"Tiempo.h"

Tiempo::Tiempo():hora(0), minuto(0), segundo(0) {}

void Tiempo::establecerTiempo(int h, int m, int s) {
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hora = h;
        minuto = m;
        segundo = s;
    } else {
        throw std::invalid_argument("hora, minuto y/o segundo estan fuera de rango.");
    }
}

void Tiempo::imprimirEstandar() const {
    std::cout <<std::setfill('0') <<std::setw(2) <<hora <<":"
              <<std::setw(2) <<minuto <<":" <<std::setw(2) <<segundo;
}

void Tiempo::imprimirUniversal() const {
    std::cout <<((hora == 0 || hora == 12) ? 12 : hora % 12) <<":"
              <<std::setfill('0') <<std::setw(2) <<minuto <<":" <<std::setw(2)
              <<segundo <<(hora < 12 ? " AM" : " PM" );
}

// Tiempo::~Tiempo()
// {
// }