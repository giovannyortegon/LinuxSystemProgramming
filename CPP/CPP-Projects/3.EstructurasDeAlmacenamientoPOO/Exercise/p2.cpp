#include<iostream>

using namespace std;

int valor=17;

int modificar(int & dato);

int main()
{
	modificar(valor);

	return (0);
}
int modificar(int &dato)
{
/*	valor *= 3;
	valor--;
	cout <<valor;*/
	cout <<valor;
	valor *=3;
	cout <<valor;
}
