#include<iostream>
#include<string>

using namespace std;

class Empleado
{
	public:
		
		float calcularSueldoMensual();
		string nombreCompleto();
		friend class Supervisor;

		void setNombre(string nombre);
		void setApellido(string apellido);
		void setsueldoAnual(float sueldoAnual);
	

	private:
		string nombre, apellido;
		float sueldoAnual;
		static const int numeroDePagos = 12;
};

class Supervisor
{
	public:
		void mostrarSueldoAnualEmpleado(const Empleado * empleado);
	private:
};

int main()
{

	Empleado * p_empleado = new Empleado();\
	p_empleado->setsueldoAnual(50500);
	Supervisor * p_supervisor = new Supervisor();
	p_supervisor->mostrarSueldoAnualEmpleado(p_empleado);

	return (0);
}
float Empleado::calcularSueldoMensual()
{
	return (sueldoAnual / numeroDePagos);
}
string Empleado::nombreCompleto()
{
	return (nombre + " " + apellido);
}
void Empleado::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Empleado::setApellido(string apellido)
{
	this->apellido = apellido;
}
void Empleado::setsueldoAnual(float sueldoAnual)
{
	this->sueldoAnual = sueldoAnual;
}
void Supervisor::mostrarSueldoAnualEmpleado(const Empleado * empleado)
{
	cout <<"El sueldo anual del empleado es: " <<empleado->sueldoAnual <<endl;
}
