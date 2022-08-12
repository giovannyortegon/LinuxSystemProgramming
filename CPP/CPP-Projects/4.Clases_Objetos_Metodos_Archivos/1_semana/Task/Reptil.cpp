#include "Inicio.h"
#include "Reptil.h"

// Constructor
Reptil::Reptil(string nom, string t, string t_sang, string es):
Inicio(nom, t, t_sang), tipo_escamas(es)
{
    setEscamas(tipo_escamas);
}
// Metodos
void Reptil::setEscamas(string es)
{
    tipo_escamas = es;
}
string Reptil::getEscamas() const
{
    return tipo_escamas;
}