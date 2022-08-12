#include "DiaAnyo.h"

int main()
{
    DiaAnyo * hoy;
    DiaAnyo * cumpleanyos;
    int d, m;

    cout <<"Introduzca fecha de hoy, dia: " ;
    cin >>d;

    cout <<"Introduzca el numero de mes: ";
    cin >>m;

    hoy = new DiaAnyo(d, m);

    cout <<"Introduzca fecha de nacimiento, dia: ";
    cin >>d;
    cout <<"Introduzca el numero de mes: ";
    cin >>m;
    cumpleanyos = new DiaAnyo(d, m);
    
    cout <<" la fecha de hoy es: ";
    hoy->visualizar();
    
    cout <<" su fecha de nacimiento es: ";
    cumpleanyos->visualizar();

    if (hoy->igual(*cumpleanyos))
        cout <<"Feliz Cumpleanyos!" <<endl;
    else
        cout <<"Feliz dia!" <<endl;

    return (0);
}
