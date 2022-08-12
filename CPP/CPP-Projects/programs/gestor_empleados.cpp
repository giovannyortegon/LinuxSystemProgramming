#include<iostream>
#include<string>

class Supervisor;

using namespace std;

class Empleado
{
	public:
		Empleado(string nombre, string apellido);
		void setNombre(string nombre);
		void setApellido(string apellido);
		void setSueldoAnual(float sueldoAnual);
		string getNombre() const;
		string getApellido() const;
		string nombreCompleto();
		friend float calcularSueldoMedioAnualPorDepartamento(Supervisor * supervisor, Empleado * empleado1, Empleado * empleado2);

	private:
		string nombre, apellido;
		float sueldoAnual;
		static const int numeroDePagos = 12;
};

class Supervisor
{
	public:
		
		void setSueldoAnual(float sueldoAnual);
		friend float calcularSueldoMedioAnualPorDepartamento(Supervisor * supervisor, Empleado * empleado1, Empleado * empleado2);
		
	
	private:
		float sueldoAnual;
		static const int numeroDePagos = 12;

};

float calcularSueldoMedioAnualPorDepartamento(Supervisor * supervisor, Empleado * empleado1, Empleado * empleado2)
{
	return (supervisor->sueldoAnual + empleado1->sueldoAnual + empleado2->sueldoAnual) / 3;
}

int main()
{

	Empleado * p_empleado1 = new Empleado("Eliezer", "Gaitan");

	cout <<p_empleado1->nombreCompleto();

	return (0);
}

void Empleado::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Empleado::setApellido(string apellido)
{
	this->apellido = apellido;
}
string Empleado::nombreCompleto()
{
	return (nombre + " " + apellido);
}
void Empleado::setSueldoAnual(float sueldoAnual)
{
	this->sueldoAnual = sueldoAnual;
}
void Supervisor::setSueldoAnual(float sueldoAnual)
{
	this->sueldoAnual = sueldoAnual;
}
Empleado::Empleado(string nombre, string apellido)
{
	this->nombre = nombre;
	this->apellido = apellido;
}
string Empleado::getNombre() const
{
	return nombre;
}
string Empleado::getApellido() const
{
	return apellido;
}
