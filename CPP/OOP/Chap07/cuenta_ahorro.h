/*
 * cuenta_ahorro.h
 */
#ifndef __CUENTA_AHORRO_H__
#define __CUENTA_AHORRO_H__

#include"cuenta.h"

class CCuentaAhorro: public CCuenta {
    private:
        double cuotaMantenimiento;

    public:
        // CCuentaAhorro();
        CCuentaAhorro(std::string nom = "sin nombre", std::string cue = "0000", double sal = 0.0, double tipo = 0.0, double mant = 0.0);
        CCuentaAhorro(const CCuentaAhorro & ca);
        CCuentaAhorro &operator =(const CCuentaAhorro & ca);
        ~CCuentaAhorro();
        bool asignarCuotaManten(double);
        double obtenerCuotaManten() const;
        void comisiones();
        double instereses();
};

#endif /* __CUENTA_AHORRO_H__ */