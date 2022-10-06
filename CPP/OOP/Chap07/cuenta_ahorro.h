/*
 * cuenta_ahorro.h
 */
#ifndef __CUENTA_AHORRO_H__
#define __CUENTA_AHORRO_H__

#include"cuenta.h

class CCuentaAhorro: public CCuenta {
    private:
        double cuotaMantenimiento;

    public:
        CCuentaAhorro();
        bool asignarCuotaManten(double);
        double obtenerCuotaManten() const;
        void comisiones();
        double instereses();
};

#endif /* __CUENTA_AHORRO_H__ */