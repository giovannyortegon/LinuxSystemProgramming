#include "Articulo.h"

Articulo::Articulo()
{
    clave = 0;
    existencia = 0;
    precio = 0;
}
// pone al objeto los valores recibidos como parámetro
void Articulo::inicializa(int cve, int exis, double pre)
{
    clave = cve;
    existencia = exis;
    precio = pre;
}
// Regresa el precio
double Articulo::getPrecio()
{
    return precio;
}
// Regresa clave
int Articulo::getClave()
{
    return clave;
}
// Regresa la cantidad en existencia
int Articulo::getExistencia()
{
    return existencia;
}
// Agrega cant a la cantidad de articulo en existencia
void Articulo::registraEntrada(int cant)
{
    existencia += cant;
}
// si no hay suficientes articulos regresa 0, si hay suficientes
int Articulo::registraSalida(int cant)
{
    if (cant > existencia)
        return 0;
    else
    {
        existencia -= cant;
        return 1;
    }
}
