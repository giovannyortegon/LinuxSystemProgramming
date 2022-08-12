#include<iostream>

using namespace std;

int main()
{
	const int N_ELEMENTOS = 10;
	int m[N_ELEMENTOS];
	int i = 0;

	cout <<"Introducir los valores de la matriz.\n";

	// Entrada de datos
	for (i = 0; i < N_ELEMENTOS; i++)
	{
		cout <<"n[" <<i <<"] = ";
		cin >>m[i];
	}
	// Salida de datos
	cout <<"\n\n";

	for (i = 0; i < N_ELEMENTOS; i++)
		cout <<m[i] <<' ';

	cout <<"\n\nFin del proceso.\n";
}
