#include<iostream>
#include"fecha.h"

using namespace std;

bool CFecha::anyoBisiesto(int aaaa) {
    return ((aaaa % 4 == 0) && (aaaa % 100 != 0) || (aaaa % 400 == 0));
}

bool CFecha::asignarFecha() {
    struct tm * fh;
    time_t segundos;

    time(&segundos);
    fh = localtime(&segundos);

    dia = fh->tm_mday;
    mes = fh->tm_mon;
    // anyo = fh->tm_year;
    anyo = fh->tm_year + 1900;

    return true;
}

bool CFecha::asignarFecha(int dd) {
    asignarFecha();
    if (!fechaValida(dd, mes, anyo)) {
        cout <<"Fecha incorrecta. Se asigna 01/01/2001.\n";
        dia = 1; mes = 1; anyo = 2001;

        return false;
    }

    dia = dd;

    return true;
}

bool CFecha::asignarFecha(int dd, int mm) {
    asignarFecha();
    if (!fechaValida(dd, mm, anyo)) {
        cout <<"Fecha incorrecta. Se asigna 01/01/2001.\n";
        dia = 1; mes = 1; anyo = 2001;

        return false;
    }

    dia = dd; mes = mm;

    return true;
}

bool CFecha::asignarFecha(int dd, int mm, long aaaa) {
    if (!fechaValida(dd, mm, aaaa)) {
        cout <<"Fecha incorrecta. Se asigna 01/01/2001.\n";
        dia = 1; mes = 1; anyo = 2001;

        return false; 
    }

    dia = dd; mes = mm; anyo = aaaa;
    return true;
}

void CFecha::obtenerFecha(int &dd, int &mm, long &aaaa) {
    dd = dia; mm = mes; anyo = aaaa;
}

bool CFecha::fechaValida(int dd, int mm, int aaaa) {
    bool diaCorrecto, mesCorrecto, anyoCorrecto;
    anyoCorrecto = (aaaa >= 1582);
    mesCorrecto = (mm >= 1) && (mm <= 12);

    switch (mm)
    {
    case 2:
        if (anyoBisiesto(aaaa))
            diaCorrecto = (dd >= 1) && (dd <= 29);
        else
            diaCorrecto = (dd >= 1) && (dd <= 28);
        break;

    case 4: case 6: case 9: case 11:
        diaCorrecto = (dd >= 1) && (dd <= 30);
        break;
    
    default:
        diaCorrecto = (dd >= 1) && (dd <= 31);
        break;
    }

    return diaCorrecto && mesCorrecto && anyoCorrecto;
}