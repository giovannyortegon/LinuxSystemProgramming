#include<iostream>
#include<string>

using namespace std;

int main()
{
	int identificador;
	string nombre;
	string apellido;

	cout<< "Hola "<<endl;
	cout<< "Por favor, instroduzca la siguiente informacion" <<endl;

	cout<<"Identificador: ";
	cin>>identificador;

	cout <<"Nombre: ";
	cin>>nombre;

	cout<<"Apellido: ";
	cin>>apellido;

	cout<<"El identificador del empleo "<<nombre<<" "<<apellido<<" es el numero " <<identificador<<endl;

	return (0);
}
