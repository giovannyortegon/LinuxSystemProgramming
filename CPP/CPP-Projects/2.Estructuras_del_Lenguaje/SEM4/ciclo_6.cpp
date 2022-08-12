#include<iostream>

using namespace std;

int main()
{
	int edad, hombres = 0, mujeres = 0, edades_gm = 0, edades_gf = 0;
	char genero;
	float promedio_gm, promedio_gf;

	for (int i = 0; i <= 4; i++)
	{
		cout <<"Digite el genero de las personas M/F: ";
		cin >>genero;
		cout <<"Digite la edad de la persona: ";
		cin >> edad;

		if (genero == 'M')
		{
			hombres++;
			edades_gm = edades_gm + edad;
		}
		else if (genero == 'F')
		{
			mujeres++;
			edades_gf = edades_gf + edad;
		}
		else
		{
			i--;
			cout <<"Opcion no valida.\n"
		}
	}

	promedio_gm = edades_gm / hombres;
	promedio_gf = edades_gf / mujeres;

	cout <<"Total de Hombres: " <<hombres <<endl;
	cout <<"Total promedio de edades de Hombres: " <<promedio_gm <<endl;

	cout <<"Total de Mujeres: " <<hombres <<endl;
	cout <<"Total promedio de edades de Mujeres: " <<promedio_gf <<endl;

	return EXIT_SUCCESS;
}
