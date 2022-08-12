/*
 * Actividad 3 - SENA
 * Aplicación en C++ que le pregunte al usuario la edad de su hijo.
 * Si el niño tiene entre 0 y 6 años el programa debe imprimir que el
 * niño pertenece al grupo de la primera infancia. Si la edad está entre
 * los 6 y los 12 años el programa debe imprimir que el niño pertenece
 * al grupo de la segunda infancia; y en caso de que el niño tenga 
 * entre 12 y 18 años el mensaje impreso dirá que pertenece al grupo
 * de los adolescentes.
*/
#include<iostream>	// Libreria que maneja el flujo de entrada/salida

using namespace std;	// Uso directode las funciones std

int main()
{
	int edad;	// Declaracion de la variable edad

	cout<<"Que edad tiene su hijo: "<<endl; // Solicita la edad
	cin>>edad; // Guarda en memoria el valor

	if (edad >= 0 && edad <= 6) // pregunta si la edad es de 0 a 6
		cout<<"El niño pertenece al grupo de la primera infancia."<<endl;
	else if (edad > 6 && edad <= 12) // si edad es mayor a 6 hasta 12 años
		cout<<"El niño pertenece al grupo de la segunda infancia."<<endl;
	else if (edad > 12 && edad <= 18) // si es de 12 años hasta 18 años
		cout<<"El niño pertenece al grupo de los adolescentes."<<endl;

	return 0;
}
