#include "Operaciones.h"

// Constructores
Operaciones::Operaciones()
:numero1(1), numero2(1) {}

Operaciones::Operaciones(int n1)
:numero1(n1), numero2(n1) {}

Operaciones::Operaciones(int n1, int n2)
:numero1(n1), numero2(n2) {}

Operaciones::Operaciones(double n1, double n2)
:numero1(n1), numero2(n2) {}

Operaciones::Operaciones(string n1, string n2)
:numero1(atoi(n1.c_str())), numero2(atoi(n2.c_str())) {} 

// Destructor
Operaciones::~Operaciones() {}

// Metodos operaciones matematicas
void Operaciones::ImprimirEntrada()
{
    cout <<"Numeros de entrada (" <<numero1 <<", " <<numero2 <<") " <<endl;
}
void Operaciones::Suma()
{
    cout <<"La suma es: " <<numero1 + numero2 <<endl;
}
void Operaciones::Resta()
{
    cout <<"La Resta es: " <<numero1 - numero2 <<endl;   
}
void Operaciones::Multiplicacion()
{
    cout <<"La Multiplicacion: " <<numero1 * numero2 <<endl;
}
void Operaciones::Division()
{
    if (numero2 == 0)
        cout <<"No es posible dividir entre 0" <<endl;
    else
        cout <<"La division es: " <<numero1 / numero2 <<endl;   
}
void Operaciones::Potencia()
{
    cout <<"La potencia es: " <<pow(numero1, numero2) <<endl;
}