#include<iostream>

using namespace std;

int main()
{
	float lado_1, lado_2, base_Mayor, base_Menor, perimetro;

	cout <<"PROGRAMA PARA HALLAR EL PERIMETRO DE UN TRAPECIO..."<<endl <<endl;
	cout <<"Digite el lado 1: " <<endl;
	cin >>lado_1;
	cout <<endl;

	cout <<"Digite el lado 2: " <<endl;
	cin >> lado_2;
	cout <<endl;

	cout <<"Digite la Base Mayor: " <<endl;
	cin >>base_Mayor;
	cout <<endl;

	cout <<"Digite la Base Menor: " <<endl;
	cin >>base_Menor;
	cout <<endl;

	perimetro = lado_1  + lado_2 + base_Mayor + base_Menor;
	cout <<"El Perimetro del Trapecio es: " <<perimetro <<endl;

	return EXIT_SUCCESS;
}
