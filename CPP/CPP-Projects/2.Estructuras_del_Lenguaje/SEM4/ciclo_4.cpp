#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int velocidad, carro = 1, mayor = 0;
	
	do
	{
		cout <<"Digite la velocidad del auto numero " <<carro <<": ";
		cin >> velocidad;
		
		if (velocidad > mayor)
		{
			mayor = velocidad;
		}
		carro++;
	}
	while (carro <= 5);
	
	cout <<"La velocidad mayor es: " <<mayor <<endl;
	
	getch();
	
	return EXIT_SUCCESS;
}