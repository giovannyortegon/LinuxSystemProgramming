/*
 * cuenta.h - clase CCuenta
 */
#ifndef _CUENTA_H_
#define _CUENTA_H_

#include<string>

class CCuenta
{
    private:
        std::string nombre;
        std::string cuenta;
        double saldo;
        double tipoDeInteres;

    public:
        // CCuenta();
        CCuenta(std::string nom = "sin nombre", std::string cue = "0000",
                double sal = 0.0, double tipo = 0.0);
        ~CCuenta();
        CCuenta(const CCuenta &cc);
        CCuenta &operator=(const CCuenta &ca);
        bool asignarNombre(std::string nom);
        std::string obtenerNombre() const;
        bool asignarCuenta(std::string cue);
        std::string obtenerCuenta() const;
        double obtenerSaldo() const;
        void comisiones();
        double intereses();
        bool ingreso(double cantidad);
        void reintegro(double cantindad);
        double obtenerTipoDeInteres() const;
        bool asignarTipoDeInteres(double tipo);
};

#endif /* _CUENTA_H_ */