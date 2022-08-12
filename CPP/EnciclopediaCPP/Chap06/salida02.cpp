#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main(void)
{
	double coef[] = {5198.0, 3.21, 46.32, 506.5, 2002.38};
	string prov[] = {"Madrid", "Sevilla", "Valencia", "Catabrian", "Barcelona"};

	// Salida de resultados alineados en columnas
	cout <<setiosflags(ios::fixed);		// formato con coma flotante
	for (int i = 0; i < sizeof(coef) / sizeof(double); i++)
		cout <<setiosflags(ios::left)		// justificacion a la izquierda
			 <<setw(15)						// ancho cadenas de caracteres
			 <<setfill('.')					// caracter de relleno
			 <<prov[i]						// escribe la provincia
			 <<resetiosflags(ios::left)		// suprime justificacion
			 <<setw(10)						// ancho para las cantidades
			 <<setprecision(2)				// dos decimales
			 <<coef[i] <<endl;				// escribe cantidades y '\n'

	return (0);
}
