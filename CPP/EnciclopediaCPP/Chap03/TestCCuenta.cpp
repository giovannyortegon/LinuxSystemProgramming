#include<iostream>
#include<string>

/*
 * Clase de los objetos CCuenta
 * Atributos:
 *	nombrre, cuenta, saldo y tipos de interes
 * Metodos:
 *	asignar / obtener nombre
 *	asignar / obtener cuenta
 *	estado de la cuenta (saldo)
 *	ingreso
 *	reintegro
 *	asignar / obtener tipo de interes
 */
using namespace std;

class CCuenta
{
	// Atributos
	private:
		string nombre;
		string cuenta;
		double saldo;
		double tipoDeInteres;

	// Metodos
	public:
		CCuenta()
		{
			//cout <<"Objeto cuenta fue creado.\n";
			saldo = 0.0;
			tipoDeInteres = 0.0;
		}
		CCuenta(string nom, string cue, double sal, double tipo)
		{
			asignarNombre(nom);
			asignarCuenta(cue);
			saldo = sal;
			tipoDeInteres = tipo;
		}
		void asignarNombre(string nom)
		{
			if (nom.length() == 0)
			{
				cout <<"Error: cadena vacia.\n";
				return;
			}
			nombre = nom;
		}
		string obtenerNombre()
		{
			return nombre;
		}
		void asignarCuenta(string cue)
		{
			if (cue.length() == 0)
			{
				cout <<"Error: cuenta no valida.\n";
				return;
			}
			cuenta = cue;
		}
		string obtenerCuenta()
		{
			return cuenta;
		}

		double estado()
		{
			return saldo;
		}

		void ingreso(double cantidad)
		{
			if (cantidad < 0)
			{
				cout <<"Error: cantidad negativa.\n";
				return;
			}
			saldo = saldo + cantidad;
		}

		void reintegro(double cantidad)
		{
			if (saldo - cantidad < 0)
			{
				cout <<"Error: no dispone de saldo.\n";
				return;
			}
			saldo = saldo - cantidad;
		}

		void asignarTipoDeInteres(double tipo)
		{
			if (tipo < 0)
			{
				cout <<"Error: tipo no valido.\n";
				return;
			}
			tipoDeInteres = tipo;
		}

		double obtenerTipoDeInteres()
		{
			return tipoDeInteres;
		}
};
class CCuentaAhorro: public CCuenta
{
	// Atributos
	private:
		double cuotaMantenimiento;
	// Metodos
	public:
		CCuentaAhorro(){}	// constructor sin parametros

		CCuentaAhorro(string nom, string cue, double sal,
			double tipo, double mant):
			CCuenta(nom, cue, sal, tipo)	// Invoca al constructor CCuenta
		{
			asignarCuotaManten(mant);		// Inicia cuotaMantenimiento
		}

		void asignarCuotaManten(double cantidad)
		{
			if (cantidad < 0)
			{
				cout <<"Error: cantidad negativa\n";
				return;
			}
			cuotaMantenimiento = cantidad;
		}
		double obtenerCuotaManten()
		{
			return cuotaMantenimiento;
		}

		void reintegro(double cantidad)
		{
			double saldo = estado();
			double tipoDeInteres = obtenerTipoDeInteres();

			if (tipoDeInteres >= 3.5)
			{
				if (saldo - cantidad < 1500)
				{
					cout <<"Error: no dispone de esa cantidad\n";
					return;
				}
			}
			// Invocar al metodo reintegro de la clase base
			//  tambien llamada superclase
			CCuenta::reintegro(cantidad);
		}
};
/*
 * Funcion main:
 *	Punto de entrada y salida al programa
 *	Crea una cuente. cuenta01 y realiza
 *	operaciones sobre ella.
 */
int main()
{
//	CCuenta cuenta01 = CCuenta();
//	CCuenta cuenta01;
	CCuentaAhorro cuenta01;

//	CCuenta cuenta02 = CCuenta("otro nombre", "otra cuenta", 6000, 3.5);
//	CCuenta cuenta02("otro nombre", "otra cuenta", 6000, 3.5);
	CCuentaAhorro cuenta02("Otro nombre", "Otra cuenta", 6000, 3.5, 2);

	// Cobrar cuota de mantenimiento
	cuenta02.reintegro(cuenta02.obtenerCuotaManten());
	// Ingreso
	cuenta02.ingreso(6000);
	// Reintegro
	cuenta02.reintegro(10000);

	cuenta01.asignarNombre("un nombre");
	cuenta01.asignarCuenta("una cuenta");
	cuenta01.asignarTipoDeInteres(2.5);

	cuenta01.ingreso(12000);
	cuenta01.reintegro(3000);

	cout <<cuenta01.obtenerNombre() <<endl;
	cout <<cuenta01.obtenerCuenta() <<endl;
	cout <<cuenta01.estado() <<endl;
	cout <<cuenta01.obtenerTipoDeInteres() <<endl;
	cout <<endl;
	cout <<cuenta02.obtenerNombre() <<endl;
	cout <<cuenta02.obtenerCuenta() <<endl;
	cout <<cuenta02.estado() <<endl;
	cout <<cuenta02.obtenerTipoDeInteres() <<endl;

	return (0);
}
