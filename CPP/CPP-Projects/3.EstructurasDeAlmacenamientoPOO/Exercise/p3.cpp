#include<iostream>

using namespace std;

int valor=0;

void funcion1(int vlr);
void funcion2(int vlr);

int main()
{
	funcion1(valor);
	funcion2(valor);

	cout <<"valor en main: " <<valor <<endl;

	return (0);
}
void funcion1(int vlr)
{
	valor++;
	cout <<"F1: " <<valor <<endl;
}
void funcion2(int vlr)
{
	valor+=2;
	cout <<"F2: " <<valor <<endl;
}
