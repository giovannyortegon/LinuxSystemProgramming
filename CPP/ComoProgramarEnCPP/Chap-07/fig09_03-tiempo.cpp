#include<iostream>
#include<stdexcept>
#include"Tiempo.h"

int main() {
    Tiempo t;

    std::cout <<"El tiempo universal inicial es: ";
    t.imprimirUniversal();
    std::cout <<"\nEl tiempo universal estandar es: ";
    t.imprimirEstandar();

    t.establecerTiempo(13, 27, 6);

    std::cout <<"\nEl tiempo universal inicial despues es: ";
    t.imprimirUniversal();
    std::cout <<"\nEl tiempo universal estandar despues es: ";
    t.imprimirEstandar();

    try {
        t.establecerTiempo(99, 99, 99);
    } catch( std::invalid_argument &e) {
        std::cout <<"\n\nExcepcion: " <<e.what() <<std::endl;
    }

    std::cout <<"Despues de intentar valores invalidos: ";
    std::cout <<"\nTiempo universal inicial es: ";
    t.imprimirUniversal();
    std::cout <<"\nEl tiempo universal estandar es: ";
    t.imprimirEstandar();

    std::cout <<std::endl;

    return (0);
}