#include<iostream>
#include <climits>
#include<string>

using namespace std;

int main()
{
    string sCadena = "Lenguaje C++";
    char cMatrizCars[80];
    int dato_int = 0;
    long dato_long = 0;
    float dato_float = 0;
    double dato_double = 0;

    cout <<"Cadena (string):    "; cin >>sCadena;
    cout <<"Cadena (char []):   "; cin >>cMatrizCars;
    cout <<"int:                "; cin >>dato_int;
    cout <<"long:               "; cin >>dato_long;
    cout <<"float:              "; cin >>dato_float;
    cout <<"double:             "; cin >>dato_double;

    cout <<"\nDatos leidos: \n";
    cout <<sCadena <<endl;
    cout <<cMatrizCars <<endl;
    cout <<dato_int <<endl;
    cout <<dato_long <<endl;
    cout <<dato_float <<endl;
    cout <<dato_double <<endl;

    return (0);
}
