#include "Operaciones.h"

/*
 * main - punto de entrada
 */
int main(void)
{
    Operaciones op0 = Operaciones();
    Operaciones op1 = Operaciones(4);
    Operaciones op2 = Operaciones(4, 2);
    Operaciones op3 = Operaciones(3.1, 1.5);
    Operaciones op4 = Operaciones("4", "2");

// Operaciones con valores enteros por defecto
    cout <<"Operaciones con valores por defecto: "<<endl;
    op0.ImprimirEntrada();
    op0.Suma();
    op0.Resta();
    op0.Multiplicacion();
    op0.Division();
    op0.Potencia();

    cout <<endl;

 // Operaciones con tipo entero
    cout <<"Operaciones con tipo entero con un parametro: "<<endl;
    op1.ImprimirEntrada();
    op1.Suma();
    op1.Resta();
    op1.Multiplicacion();
    op1.Division();
    op1.Potencia();

    cout <<endl;

// Operaciones con tipo entero con dos parametros
    cout <<"Operaciones con tipo Entero con dos parametros: "<<endl;
    op2.ImprimirEntrada();
    op2.Suma();
    op2.Resta();
    op2.Multiplicacion();
    op2.Division();
    op2.Potencia();

    cout <<endl;

// Operaciones con tipo double
    cout <<"Operaciones con tipo double: "<<endl;
    op3.ImprimirEntrada();
    op3.Suma();
    op3.Resta();
    op3.Multiplicacion();
    op3.Division();
    op3.Potencia();

    cout <<endl;
/*
 * Operaciones con tipo string
 * contiene la misma informacion de entrada
 * a la operacin con numeros tipo enteros.
 */
    cout <<"Operaciones con tipo string: "<<endl;
    op4.ImprimirEntrada();
    op4.Suma();
    op4.Resta();
    op4.Multiplicacion();
    op4.Division();
    op4.Potencia();

    cout <<endl;

 //   getch();
// Finalizacion existosa
    return (0);
}