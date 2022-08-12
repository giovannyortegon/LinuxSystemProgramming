#include"NumeroIrracional.h"
#include <fstream>
#if defined(_WIN32)
#include<conio.h>
#endif

/**
 * main - punto de entrada
 * Return: simpre cero finalizacion exitosa
 */
int main(void)
{
	int x, y;		// almacena x = parte entera y = imaginaria
	string date_now;	// string almacena la hora de la operacion
	ofstream in_file;	// variable de salida a fichero

	// declarando e inicializando segundo termino
	NumeroIrracional b(3, 1);

	// crea o abre fichero - con opcion de agregar al final
	in_file.open("Evidencia4.txt", ios::out | ios::app);

	/* Mensage para ingresar parte entera del primer termino */
	cout <<"Ingrese los valores del primer termino a operar\n";
	cout <<"con (3, 1) como segundo termino:\n";
	cout <<"Ingrese valor Entero: ";
	cin >>x;
	cout <<"Ingrese valor Imaginario: ";
	cin >>y;

	NumeroIrracional a(x, y), c;

	cout <<"\n";

	// Operacion Suma
	c = a + b;
	date_now = c.take_time();  // Tiempo de ejecucion

	// Imprimeindo resultado e ingresandolo a fichero
	in_file <<date_now <<"Suma ";
	cout <<"Suma: ";
	in_file << a.Mostrar();
	cout <<" + ";
	in_file <<" + " <<b.Mostrar();
	cout <<" = ";
	in_file <<" = " <<c.Mostrar() <<"\n";
	cout <<"\n";

	// Operacion Resta
	c = a - b;
	date_now = c.take_time();	// tiempo de ejeucion

	// Imprimeindo resultado e ingresandolo a fichero
	in_file <<date_now;
	cout <<"Resta: ";
	in_file <<"Resta: " <<a.Mostrar();
	cout <<" - ";
	in_file <<" - " <<b.Mostrar();
	cout <<" = ";
	in_file <<" = " <<c.Mostrar() <<"\n";
	cout <<"\n";

	// Operacion Multiplicacion
	c = a * b;
	date_now = c.take_time();	// tiempo de ejecucion

	// Imprimeindo resultado e ingresandolo a fichero
	in_file <<date_now <<"Multiplicacion: ";
	cout <<"Multiplicacion: ";
	in_file <<a.Mostrar() <<" * ";
	cout <<" * ";
	in_file <<b.Mostrar();
	cout <<" = ";
	in_file <<" = " <<c.Mostrar() <<"\n";
	cout <<"\n";

	// Operacion Division
	c = a / b;
	date_now = c.take_time();	// tiempo de ejecucion

	// Imprimeindo resultado e ingresandolo a fichero
	in_file <<date_now <<"Division: ";
	cout <<"Division: ";
	in_file <<a.Mostrar();
	cout <<" / ";
	in_file <<" / " <<b.Mostrar();
	cout <<" = ";
	in_file <<" = " <<c.Mostrar() <<"\n";
	cout <<"\n";

	// cerrando fichero
	in_file.close();

#if defined(_WIN32)
	getch();
#endif

	// finalizado exitosamente
	return (0);
}
