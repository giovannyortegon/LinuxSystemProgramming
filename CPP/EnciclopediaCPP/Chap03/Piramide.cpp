#include<iostream>

using namespace std;

void bloque_espacios(int);
void bloques_filas(int);

int main(void)
{
	int filas = 0, espacios;

	cout <<"Ingrese el numero de filas: ";
	cin >>filas;

	if (filas <= 0)
	{
		cout <<"El numero debe ser mayor a 0" <<endl;
		return (1);
	}

	espacios = filas;

	for (int i = 0; i <= filas; i++)
	{
		bloque_espacios(espacios*3);
		bloques_filas(i);
		cout <<endl;
		espacios--;
	}

	return (0);
}
void bloque_espacios(int espacios)
{
	for (int i = 0; i < espacios; i++)
		cout <<" ";
}
void bloques_filas(int filas)
{
	int i, j;

	for (i = 1; i <= filas; i++)
	{	cout <<i;
		if (i < 10)
			cout <<"  ";
		else
			cout <<" ";
	}

	for (j = i-2 ;j >= 1 ; j--)
	{
		cout <<j;
		if (j >= 10)
			cout <<" ";
		else
			cout <<"  ";
	}
}
