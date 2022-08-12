#if !defined(_EMPLEADO_H_)
#define _EMPLEADO_H_

#include<iostream>

using namespace std;

/* Clase Base con nombre Empleados */
class Empleado
{
    private:
        /* almacena el nombre del Empleado */
        string empleado;

    public:
        /* Constructor */
        Empleado();
        /* Destructor */
        ~Empleado();
        /* asignar nombre */
        void setNombre(string);
        /* obtener nombre */
        string getNombre() const;

};

#endif /* _EMPLEADO_H_ */