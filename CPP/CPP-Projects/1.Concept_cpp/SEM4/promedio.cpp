#include<iostream>
#define MAX 100
/*
 *  Programa Sentencias Anidadas
 * - Calcular promedio de Notas.
 *	- Recibe cantidad de notas definidas por el usuario.
 *	- Recibe notas definidas por el usuario.
 * - Condiciones:
 *  - Aprueba con 3.5 y 5.0 e Imprime.
 *  - Con 3 y 3.5 debe imprimir - “En este momento no tiene aprobada.
 *    la materia de tecnología, pero tiene la oportunidad de recuperar.”
 *  - No aprueba con 0 a 3 e imprime "No aprobado".
*/
using namespace std;

int main()
{
	// Declara variables
	int cantidad, i, j;
	float notas[MAX], suma, promedio;

	// Recibe cantidad de notas
	cout<<" ----- Calcule el promedio de notas ----- "<<endl;
	cout<<"Ingrese cantidad de Notas: ";
	cin>>cantidad;

	suma = 0; // Inicialia suma a cero

	cout<<" ---------- Ingrese las Notas ------------"<<endl;

	/* Recibe las notas y las suma */
	for (i = 0, j = 1; i < cantidad; i++, j++)
	{
		cout<<"Ingrese nota "<<j<<": ";
		cin>>notas[i];			// Recibe notas
		suma += notas[i];		// Suma las notas recibidas
	}

	// Calcula Promedio
	promedio =  suma / cantidad;

	// Imprime promedio
	cout<<"Promedio: "<<promedio<<endl;

	/* Imprime si aprueba o no de acuerdo al promedio */
	if (promedio >= 0 && promedio < 3.0)
		cout<<"No Aprobado"<<endl;
	else if(promedio >= 3.0 && promedio < 3.5)
		cout<<"En este momento no tiene aprobada la materia de tecnología, \
			pero tiene la oportunidad de recuperar."<<endl<<endl;
	else if(promedio >= 3.5 && promedio <=5)
		cout<<"Aprobado"<<endl;

	return (0);
}
