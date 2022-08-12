#include "Inicio.h"
#include "Mamifero.h"

// Constructor
Mamifero::Mamifero(string nom, string t, string t_sang, int gest):
Inicio(nom, t, t_sang), gestacion(gest)
{
    setGestacion(gestacion);
}
// Metodos
void Mamifero::setGestacion(int gest)
{
    gestacion = gest;
}
int Mamifero::getGestacion() const
{
    return gestacion;
}