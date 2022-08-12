#include "PVentas.h"

/* Constructor */
PVentas::PVentas()
:Empleado(), NMeses(4), Meses(setMemoria(NMeses))
{
    fill(Meses, Meses + NMeses, 0);
}
/*
 * setMemoria - asigna memoria para almacenar 4 meses
 * mem: cantidad de Memoria
 * return: Retorna direccion de memoria
 */
int * PVentas::setMemoria(unsigned int mem)
{
    try
    {
        int * memoria = new int[mem];
        return memoria;
    }
    catch (bad_alloc e)
    {
        cout <<"Memoria Insuficiente";
        exit(-1);
    }
}
/*
 * setMes - asigna un valor a cada elemento del arreglo
 * elemento: valor por mes
 * i: numero indice
 */
void PVentas::setMes(int elemento, unsigned int i)
{
    Meses[i] = elemento;
}
/*
 * getMes - obtiene valor del me deacuerdo al indice
 * i: indice
 */
int PVentas::getMes(unsigned int i) const
{
    return Meses[i];
}
/*
 * numeroElementos - obtiene el largo del arreglo
 */
int PVentas::numeroElementos() const
{
    return NMeses;
}
/*
 * calcularPromedio - genera un promedio por empleado
 */
double PVentas::calcularPromedio()
{
    int i = 0, suma = 0;
    double promedio;
    
    while (i < NMeses)
    {
        suma += Meses[i++];
    }

    return (suma / NMeses);
}
/*
 * visualizar - muestra cada elemento del arreglo
 */
void PVentas::Visualizar()
{
    int i = 0;

    while (i < NMeses)
    {
        cout <<"Mes "<<i + 1 <<": $";
        cout <<Meses[i++] <<" ";
    }
}
/*
 * Destructor
 */
PVentas::~PVentas()
{
    delete [] Meses;
}