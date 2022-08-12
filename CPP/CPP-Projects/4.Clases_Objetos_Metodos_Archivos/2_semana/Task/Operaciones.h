#if !defined(_OPERACIONES_H_)
#define _OPERACIONES_H_

#include<iostream>
#include<cstdlib>
#include<math.h>
//#include<conio.h>

using namespace std;

// Clase
class Operaciones
{
    private:
        // Atributos
        double numero1;
        double numero2;
    public:
        Operaciones();          // Constructor para numeros tipo enteros
        Operaciones(int);          // Constructor para numeros tipo enteros
        Operaciones(int, int);          // Constructor para numeros tipo enteros
        Operaciones(double, double);    // Constructor para numeros tipo double
        Operaciones(string, string);    // Constructor para tipo string
        ~Operaciones();
        // Metodos
        void ImprimirEntrada();
        void Suma();
        void Resta();
        void Multiplicacion();
        void Division();
        void Potencia();
};

#endif // _OPERACIONES_H_