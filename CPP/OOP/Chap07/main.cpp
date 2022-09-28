#include<iostream>
#include"cuenta.h"

using namespace std;

void visualizar(CCuenta &);

int main() {
    try {
        CCuenta cuenta01("Un nombre", "Una cuenta", -10000, 3.5);
        visualizar(cuenta01);
    } catch (const char * error) {
        cout <<error <<endl;
    }

    CCuenta cuenta02;
    string cuenta;
    do
        getline(cin, cuenta);
    while ( !cuenta02.asignarCuenta(cuenta));
    visualizar(cuenta02);
    
}