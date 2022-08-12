#include<iostream>

using namespace std;

int main(void)
{
	char car = 0;
	cout <<"Introducir un caracter: ";
	// Leer un caracter y almacenarlo en la variable car
	cin.get(car);
	cout <<"Caracter: " <<car
		 <<". Valor ASCII: " <<static_cast<int>(car) <<endl;

	return (0);
}
