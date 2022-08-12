#include<iostream>

using namespace std;
/*
 * main - Tablas de Miltiplicar
 */
int main()
{
// Inicializacion de componentes Tabla Multiplicar
	int i = 1, tabla,multiplicador, producto;

// Despliega Menu
	cout <<"Tablas de Multiplicar" <<endl;
	while (i < 10)
	{
		cout <<"Tabla del " <<i <<endl;
		i++;
	}

// Solicita al usuario seleccionar de acuerdo al menu
	cout <<endl <<"Seleccione una tabla de multiplicar: ";
	cin >>tabla;
	if (tabla > 0 && tabla < 10)
	{
		for (multiplicador = 1; multiplicador < 10; multiplicador++)
		{
			producto = tabla * multiplicador;
			cout <<tabla <<" x " <<multiplicador <<" = " <<producto <<endl;
		}
	}

// Realiza una pausa en el sitema
	system("pause");

// El programa finalizo correctamente
	return EXIT_SUCCESS;
/* Giovanny Ortegon */
}
