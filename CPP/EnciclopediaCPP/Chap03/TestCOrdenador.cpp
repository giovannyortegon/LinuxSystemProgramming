#include<iostream>

using namespace std;

class COrdenador
{
	private:
		string marca;
		string procesador;
		float peso;
		bool encendido;
		bool pantalla;
		bool aplicacion;
	public:
		COrdenador();
		~COrdenador();
		string obtenerMarca() const;
		string obtenerProcesador() const;
		float obtenerPeso()const;
		void asignarMarca(string mar);
		void asignarProcesador(string proc);
		void asignarPeso(float pes);
		void EncenderOrdenador();
		void CargarAplicacion();
		void CerrarAplicacion();
		void ApagarOrdenador();
		void Estado();
};

int main()
{
	COrdenador miOrdenador;

	miOrdenador.asignarMarca("Toshiba");
	miOrdenador.asignarProcesador("Intel");
	miOrdenador.asignarPeso(3);
	miOrdenador.EncenderOrdenador();
	miOrdenador.CargarAplicacion();
	miOrdenador.Estado();
	miOrdenador.CerrarAplicacion();
	miOrdenador.ApagarOrdenador();
	miOrdenador.Estado() const;

	return (0);
}

COrdenador::COrdenador()
{
	cout <<"Constructor.\n";
}

COrdenador::~COrdenador()
{
	cout <<"Destructor.\n";
}

void COrdenador::asignarMarca(string mar)
{
	if (mar.length() == 0)
		marca = "marca desconocida.";
	else
		marca = mar;
}

void COrdenador::asignarProcesador(string proc)
{
	if (proc.length() == 0)
		procesador = "desconocido";
	else
		procesador = proc;
}

void COrdenador::asignarPeso(float pes=0.0)
{
	if (pes <= 0)
		peso = 0;
	else
		peso = pes;
}

string COrdenador::obtenerMarca() const
{
	return marca;
}

string COrdenador::obtenerProcesador() const
{
	return procesador;
}

float COrdenador::obtenerPeso() const
{
	return peso;
}

void COrdenador::CargarAplicacion()
{
	if (aplicacion == true)
		cout <<"aplicacion iniciada.\n";
	else
		aplicacion = true;
		cout <<"Cargando aplicacion.\n";
}
void COrdenador::CerrarAplicacion()
{
	if (aplicacion == false)
		cout <<"aplicacion cerrada.\n";
	else
		aplicacion = true;
		cout <<"Cerrando aplicacion.\n";
}

void COrdenador::EncenderOrdenador()
{
	if (encendido == true)
	{
		cout <<"El ordenador esta encendido.\n";
	}
	else
	{
		encendido = true;
		pantalla = true;
		cout <<"El ordenador ha sido encendido.\n";
	}
}
void COrdenador::ApagarOrdenador()
{
	if (encendido == false)
		cout <<"El ordenador esta apagado.\n";
	else
	{
		encendido = false;
		pantalla = false;
		cout <<"El ordenador ha sido apagado.\n";
	}
}
void COrdenador::Estado() const
{

	if (encendido == true)
	{
		cout <<"El ordenador esta encendido\n";
		cout <<"\nEl estado del ordenador es el siguiente:";
		cout <<"\nMarca: " <<marca;
		cout <<"\nProcesador: " << procesador;
		cout <<"\nPeso: " <<peso <<" kg.\n\n";
	}
	else
	{
		cout <<"El ordenador esta apagado\n";
	}

	if (pantalla == true)
	{
		cout <<"La pantalla esta activa\n";
	}
	else
	{
		cout <<"La pantalla esta desactivada\n";
	}
}
