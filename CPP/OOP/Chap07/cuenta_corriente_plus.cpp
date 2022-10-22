#include<iostream>
#include"fecha.h"
#include"cuenta_corriente_plus.h"

// Clase CCuentaCorrientePlus: clase derivada de CCuentaCorriente
// Metodos
CCuentaCorrientePlus::CCuentaCorrientePlus(std::string nom, std::string cue, double sal,
                             double tipo, double imptrans, int transex):
CCuentaCorriente{ nom, cue, sal, tipo, imptrans, transex } {}

double CCuentaCorrientePlus::intereses() {
    CFecha fecha;
    int dia, mes, anyo;
    fecha.obtenerFechaActual(dia, mes, anyo);
    if (dia != 1 || obtenerSaldo() < 3000) return 0.0;

    // Acumular intereses mensual solo los dias 1 de cada mes
    double interesesProducidos = 0.0;
    interesesProducidos = obtenerSaldo() * obtenerTipoDeInteres() / 1200.0;
    ingreso(interesesProducidos);

    // Este ingreso no debe incrementar las transacciones
    decrementTransacciones();

    return interesesProducidos;
}
CCuentaCorrientePlus::~CCuentaCorrientePlus() {}