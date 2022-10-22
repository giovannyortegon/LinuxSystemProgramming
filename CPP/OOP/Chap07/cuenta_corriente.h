#ifndef __CUENTA_CORRIENTE_H__
#define __CUENTA_CORRIENTE_H__

#include"cuenta.h"
// #include"fecha.h"

class CCuentaCorriente: public CCuenta {
    private:
        int transacciones;
        double importePorTrans;
        int transExenta;

    public:
        CCuentaCorriente(std::string nom = "sin nombre",
                         std::string cue = "0000",
                         double sal = 0.0, double tipo = 0.0,
                         double imptrans = 0.0, int transex = 0);
        CCuentaCorriente(const CCuentaCorriente & cc);
        CCuentaCorriente &operator =(const CCuentaCorriente & cc);
        ~CCuentaCorriente();
        void decrementTransacciones();
        bool asignarImportePorTrans(double);
        double obtenerImportePorTrans() const;
        bool asignarTransExentas(int);
        int obtenerTransExentas() const;
        void ingreso(double);
        void reintegro(double);
        void comisiones();
        double intereses();
};

#endif /* __CUENTA_CORRIENTE_H__ */