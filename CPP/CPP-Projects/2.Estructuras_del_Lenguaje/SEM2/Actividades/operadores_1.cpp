#include<iostream>

using namespace std;

int main()
{
	int a, b, suma, resta, mult, div, mod, resultado;

	cout <<"Digite Dos Numeros para realizar las operaciones...";
	cout <<endl <<endl <<"Digite el primer Numero a = " <<endl;
	cin >> a;
	cout <<endl <<"Digite el segundo numero b= " <<endl;
	cin >>b;

	suma = a + b;
	resta = a - b;
	mult = a * b;
	div = a / b;
	mod = a % b;

	cout <<endl <<"El resultado con operadores es... ";
	cout <<endl <<endl;

	cout <<a <<" + " <<b <<" = "<<suma <<endl;
	cout <<a <<" - " <<b <<" = "<<resta <<endl;
	cout <<a <<" * " <<b <<" = "<<mult <<endl;
	cout <<a <<" / " <<b <<" = "<<div <<endl;
	cout <<a <<" % " <<b <<" = "<<mod <<endl;

	return EXIT_SUCCESS;
}
