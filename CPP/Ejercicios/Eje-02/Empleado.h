#ifndef __EMPLEADO_H__
#define __EMPLEADO_H__

#include<iostream>
#include "Persona.h"

class Empleado: protected Persona {
    private:
        int idEmpleado;
        double sueldo;

    public:
        static int contador;
        Empleado();
        Empleado(const Empleado &e);
        Empleado(std::string nom, char gen, int ed, std::string dir, int sueldo);
        ~Empleado();

        std::string Print();
};

#endif /* __EMPLEADO_H__ */