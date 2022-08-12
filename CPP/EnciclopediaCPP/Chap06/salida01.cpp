#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
	int a = 12345;
	float b = 54.865F;

	cout <<a <<endl;
	cout <<'\n' <<setw(10) <<"abc" <<setw(10) <<"abcdef" <<endl;
	cout <<left;			// Ajusta a la izquierda
	cout <<'\n' <<setw(10) <<"abc" <<setw(10) <<"abcdef" <<endl;
	cout <<endl;
	cout <<right;

	// se activa el formato de coma flotante con dos decimales
	cout <<fixed <<setprecision(2);
	cout <<setw(15) <<b <<endl;			// escribe b con dos decimales
	cout <<setw(15) <<b / 10 <<endl;

	return (0);
}
