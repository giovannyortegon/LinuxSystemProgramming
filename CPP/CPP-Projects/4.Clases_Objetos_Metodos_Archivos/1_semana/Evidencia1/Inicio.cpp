#include "Inicio.h"

// Constructor
Inicio::Inicio(string nom, string t, string t_sang):
nombre(nom), tipo(t), tipo_sangre(t_sang)
{
	setNombre(nombre);
	setTipo(tipo);
	setTipoSangre(tipo_sangre);
}
// Metodos
void Inicio::setNombre(string nom)
{
	nombre = nom;
}
string Inicio::getNombre() const
{
	return nombre;
}
void Inicio::setTipo(string t)
{
	tipo = t;
}
string Inicio::getTipo() const
{
	return tipo;
}
void Inicio::setTipoSangre(string t_sang)
{
	tipo_sangre = t_sang;
}
string Inicio::getTipoSangre() const
{
	return tipo_sangre;
}