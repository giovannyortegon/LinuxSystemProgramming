#include<iostream>

int numero1=10;

void verNumero(int nro);

using namespace std;

int main()
{
	int numero2 = 5;
	numero1++;

	cout <<numero1;
	verNumero(numero2);

	return (0);
}

void verNumero(int x)
{
	int operacion;

	operacion = x + numero1;

	cout <<"operacion: " <<operacion <<endl;
}
