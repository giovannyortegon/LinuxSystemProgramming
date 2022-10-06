#include<iostream>
#include"cuenta.h"

using namespace std;

CCuenta::CCuenta(string nom = "sin nombre", string cue = "0000", double sal = 0.0, double tipo = 0.0) {
    // validar datos asignados
    if (!asignarNombre(nom) || !asignarCuenta(cue) || !ingreso(sal) || !asignarTipoDeInteres(tipo)) {
        throw "Datos incorrectos";
    }
}
CCuenta::~CCuenta(){}
bool CCuenta::asignarNombre(string nom) {
    if (nom.length() != 0) {
        nombre = nom;
    } else {
        cerr <<"Error: cadena nombre vacia\n";
    }

    return (nom.length() != 0);
}
string CCuenta::obtenerNombre() const {
    return (nombre);
}
bool CCuenta::asignarCuenta(string cue) {
    if (cue.length() != 0)
        cuenta = cue;
    else
        cerr <<"Error: cuenta no valida.\n";

    return (cue.length() != 0);
}
string CCuenta::obtenerCuenta() const {
    return (cuenta);
}
double CCuenta::obtenerSaldo() const {
    return (saldo);
}
void CCuenta::comisiones() {
    return;
}
double CCuenta::intereses() {
    return (0.0);
}
bool CCuenta::ingreso(double cantidad) {
    if (cantidad >= 0)
        saldo += cantidad;
    else
        cerr <<"Error: ingreso negativo.\n";

    return (cantidad >= 0);
}
void CCuenta::reintegro(double cantindad) {
    if (saldo - cantindad < 0) {
        cerr <<"Error: no dispone de saldo.\n";
        return;
    }
    saldo -= cantindad;
}
double CCuenta::obtenerTipoDeInteres() const {
    return (tipoDeInteres);
}
bool CCuenta::asignarTipoDeInteres(double tipo) {
    if (tipo >= 0)
        tipoDeInteres = tipo;
    else
        cerr <<"Error: tipo no valido.\n";

    return (tipo >= 0);
}