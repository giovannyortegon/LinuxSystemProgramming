#include<iostream>

using namespace std;

int main(void)
{
	float precio = 0.0F;
	char car = 0;

	cout <<"Precio: ";
	cin >>precio;
	cin.ignore();			// limpiar buffer
	cout <<"Pulse <Enter> para continuar ";
	cin.get(car);
	cout <<"Precio = " <<precio <<endl;

	return (0);
}
