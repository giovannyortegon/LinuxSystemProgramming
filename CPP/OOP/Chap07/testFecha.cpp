#include<iostream>
#include"fecha.h"

using namespace std;

void leerFecha(int &, int &, int &);
void visualizarFecha(CFecha & fecha);

int main() {
    CFecha fecha;
    int dd = 0, mm = 0;
    int aaaa = 0;
    bool fechaValida = true;

    // fechaValida = fecha.asignarFecha();

    // do {
    //     leerFecha(dd, mm, aaaa);
    //     fechaValida = fecha.asignarFecha(dd, mm, aaaa);
    // } while(!fechaValida);

    visualizarFecha(fecha);

    return (0);
}

void leerFecha(int & dia, int & mes, int & anyo) {
    cout <<"dia: "; cin >> dia;
    cout <<"mes: "; cin >> mes;
    cout <<"anyo: "; cin >> anyo;
}

void visualizarFecha(CFecha & fecha) {
    int dd, mm, aaaa;

    fecha.obtenerFecha(dd, mm, aaaa);
    cout << dd << "/" << mm << "/" <<aaaa <<"\n";
}