#include "CGrados.h"

void CGrados::AsignarCentigrados(float gC)
{
	// Establecer el atributo grados centigrados
	gradosC = gC;
}
float CGrados::ObtenerFahrenheit() const
{
	// Retorna los grados fahrenheit equivlentes a gradosC
	return 9.0F/5.0F * gradosC + 32.0;
}
float CGrados::ObtenerCentigrados() const
{
	return gradosC;		// Retorna los grados centigrados
}
