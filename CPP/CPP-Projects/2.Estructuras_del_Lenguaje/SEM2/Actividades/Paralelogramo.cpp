#include<iostream>

using namespace std;
/*
 * main - Calcula area de un Paralelogramo
 */
int main(void)
{
   float area, altura, base;
// Ingresando informacion altura y base para encontrar el area
   cout <<"ENCONTRAR EL AREA DE UN PARALELOGRAMO" <<endl <<endl;
// Ingresando altura
   cout <<endl <<"Ingrese la altura: " <<endl <<endl;
   cin >>altura;
// Ingresando Base
   cout <<endl <<"Ingrese la base: " <<endl <<endl;
   cin >>base;
// Calcula el area
   area = altura * base;
// Limpia pantalla
   system("cls");
// Muestra el resultado del area
   cout <<"PARALELOGRAMO" <<endl <<endl;
   cout <<"Su area es: " << area <<endl <<endl;  
// Pausa en el sistema para lograr visualizar las operaciones en pantalla
   system("pause");
// Salida exitosa
   return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
