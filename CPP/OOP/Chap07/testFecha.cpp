#include<iostream>
#include"fecha.h"

using namespace std;

void leerFecha(int &, int &, long &);
void visualizarFecha(CFecha & fecha);

int main() {
    CFecha fecha;
    int dd = 0, mm = 0;
    long aaaa = 0;
    bool fechaValida = true;

    do {
        leerFecha(dd, mm, aaaa);
        fechaValida = fecha.asignarFecha(dd, mm, aaaa);
        // fechaValida = fecha.asignarFecha();
    } while(!fechaValida);

    visualizarFecha(fecha);

    return (0);
}

void leerFecha(int & dia, int & mes, long & anyo) {
    cout <<"dia: "; cin >> dia;
    cout <<"mes: "; cin >> mes;
    cout <<"anyo: "; cin >> anyo;
}

void visualizarFecha(CFecha & fecha) {
    int dd, mm;
    long aaaa;

    fecha.obtenerFecha(dd, mm, aaaa);
    cout << dd << "/" << mm << "/" <<aaaa <<"\n";
}