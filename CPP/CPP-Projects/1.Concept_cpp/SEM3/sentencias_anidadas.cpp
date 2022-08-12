#include<iostream>
/*
 *  Programa Sentencias Anidadas
 * - Calcular promedio de Notas.
 * - Recibe 4 notas. 
 * - Condiciones:
 *  - Aprueba con 3.5 y 5.0 e Imprime.
 *  - Con 3 y 3.5 debe imprimir - “En este momento no tiene aprobada.
 *    la materia de tecnología, pero tiene la oportunidad de recuperar.”
 *  - No aprueba con 0 a 3 e imprime "No aprobado".
*/
using namespace std;

int main()
{
	// Declara varibles para almacenar notas
	float promedio, nota1, nota2, nota3, nota4;

	cout<<" ----- Calcule el promedio de notas ----- "<<endl;
	cout<<" ---------- Ingrese las Notas ------------"<<endl;
	// Solicita notas
	cout<<"Nota 1: ";
	cin>>nota1;		// Guarda en nota 1
	cout<<"Nota 2: ";
	cin>>nota2;		// Guarda en nota 2
	cout<<"Nota 3: ";
	cin>>nota3;		// Guarda en nota 3
	cout<<"Nota 4: ";
	cin>>nota4;		// Guarda en nota 4

	promedio = (nota1 + nota2 + nota3 + nota4) / 4; // Calcula promedio

	cout<<"El promedio es: "<<promedio<<" "; // Imprime promedio

	/* Imprime si aprueba o no */
	if (promedio >= 0 && promedio < 3.0)
		cout<<"No Aprobado"<<endl;
	else if(promedio >= 3.0 && promedio < 3.5)
		cout<<"En este momento no tiene aprobada la materia de tecnología, \
			pero tiene la oportunidad de recuperar."<<endl<<endl;
	else if(promedio >= 3.5 && promedio <=5)
		cout<<"Aprobado"<<endl;

	return 0;
}
/* Giovanny Ortegon - Codigo programa: 2244581 */
