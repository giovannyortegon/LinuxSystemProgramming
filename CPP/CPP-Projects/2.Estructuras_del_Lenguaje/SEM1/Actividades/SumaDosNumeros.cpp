#include<iostream>

int suma(int, int);

using namespace std;

int main()
{
    int a, b;
    cout <<"Ingrese el primer numero: " <<endl;
    cin >> a;
    cout <<"Ingrese el segundo numero: " <<endl;
    cin >> b;
// Llamado a la funcion suma
   cout <<"La suma de los numeros es: " <<suma(a, b) <<endl;
   system("pause");
   return EXIT_SUCCESS;  
}
// Declaracion de la funcion con sus parametros
int suma(int numero_1, int numero_2)
{
    return numero_1 + numero_2;
}
