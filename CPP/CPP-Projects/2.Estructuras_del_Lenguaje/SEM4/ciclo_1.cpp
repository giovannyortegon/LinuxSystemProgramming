#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int numero, resultado = 0;
	
	cout <<"Digite un numero para hallar los multiplos: " <<endl;
	cin >> numero;
	cout <<"Los numeros de multiplos de " <<numero <<" son: "<<endl;
	
	while (resultado < 100)
	{
		resultado = resultado + numero;
		cout <<resultado <<endl;
	}
	 getch();
	 
	 return EXIT_SUCCESS;	
}
