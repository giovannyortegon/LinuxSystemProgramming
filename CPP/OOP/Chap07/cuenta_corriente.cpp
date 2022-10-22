#include<iostream>
#include"fecha.h"
#include"cuenta.h"
#include"cuenta_corriente.h"


CCuentaCorriente::CCuentaCorriente(std::string nom, std::string cue, double sal,
                                   double tipo, double imptrans, int transex):
                                   CCuenta{nom, cue, sal, tipo }, importePorTrans{ imptrans },
                                   transacciones {transex} {
    this->transacciones = 0;

    if (!asignarImportePorTrans(imptrans) || !asignarTransExentas(transex))
        throw "Datos incorrectos.\n";
}

CCuentaCorriente::CCuentaCorriente(const CCuentaCorriente & cc)
:CCuenta{cc}, importePorTrans{ cc.importePorTrans }, transacciones { cc.transacciones} {
    std::cout<<"\nCopiado\n";
}

CCuentaCorriente &CCuentaCorriente::operator =(const CCuentaCorriente & cc) {
    if (&cc != this) {
        CCuenta::operator=(cc);
        this->importePorTrans = cc.importePorTrans;
        this->transacciones = cc.transacciones;
    }
    std::cout<<"\nCopiado con operador\n";

    return * this;
}
CCuentaCorriente::~CCuentaCorriente() {}

void CCuentaCorriente::decrementTransacciones() {
    this->transacciones--;
}

bool CCuentaCorriente::asignarImportePorTrans(double imptrans) {
    if (imptrans >= 0)
        importePorTrans = imptrans;
    else
        std::cerr <<"Error: cantidad negativa.\n";

    return imptrans >= 0;
}

double CCuentaCorriente::obtenerImportePorTrans() const {
    return importePorTrans;
}

bool CCuentaCorriente::asignarTransExentas(int transex) {
    if (transex >= 0)
        transacciones = transex;
    else
        std::cerr <<"Error: cantidad negativa.\n";

    return transex >= 0;
}

int CCuentaCorriente::obtenerTransExentas() const {
    return transExenta;
}

void CCuentaCorriente::ingreso(double cantidad) {
    CCuentaCorriente::ingreso(cantidad);
    transacciones++;
}

void CCuentaCorriente::reintegro(double cantidad) {
    CCuenta::reintegro(cantidad);
    transacciones++;
}

void CCuentaCorriente::comisiones() {
    CFecha fecha;
    int n;
    int dia, mes, anyo;
    fecha.obtenerFechaActual(dia, mes, anyo);
    if (dia == 1) {
        n = transacciones - transExenta;
    }
    if (n > 0) reintegro(n * importePorTrans);
    transacciones = 0;
}

double CCuentaCorriente::intereses() {
    CFecha fecha;
    int dia, mes, anyo;
    fecha.obtenerFechaActual(dia, mes, anyo);
    if (dia != 1) return 0.0;
     
    // acumular intereses por mes solo los dias 1 de cada mes
    double interesesProducidos = 0.0;

    // Hasta 3000 euros al 0.5%. El resto los dias 1 de cada mes
    if (obtenerSaldo() <= 3000)
        interesesProducidos = 3000 * 0.5 / 1200.0;
    else 
        interesesProducidos = 3000 * 0.5 / 1200.0 + (obtenerSaldo() - 3000) * obtenerTipoDeInteres()/ 1200.0;
    
    ingreso(interesesProducidos);

    // este ingreso no debe incrementar las transacciones
    decrementTransacciones();

    return interesesProducidos;
}