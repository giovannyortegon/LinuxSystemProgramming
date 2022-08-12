#include "Empleado.h"

/* Constructor */
Empleado::Empleado(){}
/* asigna nombre */
void  Empleado::setNombre(string nombre)
{
    empleado = nombre;
}
/* Obtiene Nombre */
string Empleado::getNombre() const
{
    return empleado;
}
/* Destructor */
Empleado::~Empleado(){}