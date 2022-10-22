#include<iostream>
#include"fecha.h"
#include"cuenta.h"
#include"cuenta_ahorro.h"

// CCuentaAhorro::CCuentaAhorro() {}
CCuentaAhorro::CCuentaAhorro
        (std::string nom, std::string cue, double sal, double tipo, double mant):CCuenta(nom, cue, sal, tipo), cuotaMantenimiento{mant} {
            if (! this->asignarCuotaManten(mant))
                throw "Datos incorrectos";
}

CCuentaAhorro::CCuentaAhorro(const CCuentaAhorro & ca):CCuenta{ ca }, cuotaMantenimiento {ca.cuotaMantenimiento} {}

CCuentaAhorro &CCuentaAhorro::operator =(const CCuentaAhorro & ca) {
    if ( &ca != this) {
        CCuenta::operator=(ca);
        this->cuotaMantenimiento = ca.cuotaMantenimiento;
    }

    return *this;
}

CCuentaAhorro::~CCuentaAhorro() {}
bool CCuentaAhorro::asignarCuotaManten(double cantidad) {
    if (cantidad >= 0)
        this->cuotaMantenimiento = cantidad;
    else
        std::cerr <<"Error: cantidad negativa.\n";
    
    return (cantidad >= 0);
}

double CCuentaAhorro::obtenerCuotaManten() const {
    return cuotaMantenimiento;
}

void CCuentaAhorro::comisiones() {
    CFecha fecha;
    int dia, mes, anyo;
    fecha.obtenerFecha(dia, mes, anyo);

    if (dia == 1)
        reintegro(cuotaMantenimiento);

}

double CCuentaAhorro::instereses() {
    CFecha fecha;
    int dia, mes, anyo;
    fecha.obtenerFechaActual(dia, mes, anyo);

    if (dia != 1)
        return 0.0;

    double interesesProducidos = 0.0;
    interesesProducidos = obtenerSaldo() * obtenerTipoDeInteres() / 1200.0;
    ingreso(interesesProducidos);

    return interesesProducidos;
}