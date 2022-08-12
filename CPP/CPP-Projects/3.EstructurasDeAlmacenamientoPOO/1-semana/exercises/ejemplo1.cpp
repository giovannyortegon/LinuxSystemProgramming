#include<iostream>
#include<stdlib.h>

using namespace std;

class Cliente
{
	private:
		string cedula;
		string nombre;
		string telefono;
	public:
		Cliente(string, string, string);
		void comprar();
		void alquilar();
};
Cliente:: Cliente(string laCedula, string elNombre, string elTelefono)
{
    cedula = laCedula;
    nombre = elNombre;
    telefono = elTelefono;
}
void Cliente::comprar()
{
    cout <<"El cliente "  <<nombre <<" ha comprado un video juego." <<endl;
}

void Cliente::alquilar()
{
    cout <<"Video juegos alquilados a " <<nombre <<" con documento " <<cedula <<endl;
    cout <<"En caso de demoras en la entrega llamar al " <<telefono <<endl;
}
int main()
{
    Cliente cliente1 = Cliente("10278548","Luis Hurtado","3156478524");
    Cliente cliente2 = Cliente("24342548","Andrea Moreno","2627788");

    cliente1.alquilar();
    cliente2.comprar();

    return (0);
}
