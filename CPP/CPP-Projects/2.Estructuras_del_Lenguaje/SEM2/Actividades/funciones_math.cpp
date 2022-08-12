#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	cout <<"DEMOTRACION DE FUNCIONES MATEMATICAS EN C++" <<endl <<endl;
	cout <<"Funciones fmax para hallar el MAYOR  de los numeros: fmax(18.9, 18) = ";
	cout <<fmax(18.9, 18) <<endl <<endl;
	cout <<"Funciones fmin para hallar el MENOR  de los numeros: fmin(18.9, 18) = ";
	cout <<fmin(18.9, 18) <<endl <<endl;
	cout <<"Funciones ceil para redondear a una cifra superior: ceil(18.7) = ";
	cout <<ceil(18.7) <<endl <<endl;

	cout <<"Funciones floor para redondear a una cifra inferior: floor(18.7463) = ";
	cout <<floor(18.7463) <<endl <<endl;

	cout <<"Funciones pow para elevar un numero a una potencia: pow(9, 2) = ";
	cout <<pow(9, 2) <<endl <<endl;

	cout <<"Funciones sqrt para hallar la raiz cuadrada de un numero: sqrt(81) = ";
	cout <<sqrt(81) <<endl <<endl;
	cout <<"Funciones hypot para hallar la Hipotenusa de un triangulo: sqrt(81) = ";
	cout <<hypot(3, 4) <<endl <<endl;

	return EXIT_SUCCESS;
}
