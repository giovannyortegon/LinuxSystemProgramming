#include<iostream>

using namespace std;

int main()
{
	int i = 0;
	char continuar;

	cout <<"Desea contar numeros de dos en dos? s/n: ";
	cin >>continuar;

	while (continuar != 'n')
	{
		i = i + 2;
		cout <<i <<endl;
		cout <<"Desea continuar? digite 'n' para salir: ";
		cin >>continuar;
	}

	cout <<endl;

	return EXIT_SUCCESS;
}
