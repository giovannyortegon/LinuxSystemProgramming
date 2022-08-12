#include<iostream>

using namespace std;
/*
 * main - Calcula area de un Rectangulo
 */
int main(void)
{
  float area, altura, base;
// Ingresando informacion altura y base para encontrar el area
  cout <<"ENCONTRAR EL AREA DE UN RECTANGULO" <<endl <<endl;
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
  cout <<"RECTANGULO" <<endl <<endl;
  cout <<"Su area es: " << area <<endl <<endl;  
// Pausa en el sistema para lograr visualizar las operaciones en pantalla
  system("pause");
  return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
