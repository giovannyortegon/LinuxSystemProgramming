/*
 * Evidencia 4 - Giovanny Ortegon
 */
#include<iostream>
#if defined(_WIN32)
#include<conio.h>
#endif

/* Prototipo de funciones */
void mensaje_inicio();
void costo_total(double, double&);
void mensaje_final(double costo);

using namespace std;

/**
 * main - punto de entrada
 * Return: 0 si finaliza exitosamente
 */
int main(void)
{
	/**
	 * peso: almacen el peso del paquete
	 * costo: almacena el costo total a pagar
	 */
	double peso, costo;

	/* titulo del programa */
	mensaje_inicio();

	/* Solicita el peso del paquete */
	cout <<"Ingrese el peso (Kg): ";
	cin >>peso;

	/* procesa el pesoy el costo de envio */
	costo_total(peso, costo);

	/* emnsaje de cierre */
	mensaje_final(costo);

#if defined(_WIN32)
	getch();
#endif
	return (0); //finaliza exitosamente
}
/**
 * mensaje_inicio - muestra el titulo al iniciar
 */
void mensaje_inicio()
{
	cout <<"\n*****************************************\n";
	cout <<"****** Calcular el Costo del Envio ******";
	cout <<"\n*****************************************\n";
}
/**
 * costo_total - procesa el pago a traves del peso
 */
void costo_total(double peso, double &costo)
{
	/**
	 * kiloAdicional: tipo entero y almacena peso adicional en kilo
	 * cargo_fijo:	tipo double y almacena valor a pagar de acuerdo al peso
	 * valor_adicional: tipo double y almacena el valor adicional por kilo
	 */
	int kiloAdicional = 0;
	double cargo_fijo = 0;
	double valor_adicional = 0;

	/**
	 * Calculando el precio de acuerdo al peso con rangos entre:
	 * 0 - 10
	 * 10 - 30 || 30 - 50 con valor adicional
	 * mayores a 50 con valor adicional
	 */
	if (peso >=0 && peso <= 10)
	{
		cargo_fijo = 28000;
		valor_adicional = 0;
	}
	if ((peso > 10 && peso <= 30) || (peso > 30 && peso < 50))
	{
		cargo_fijo = 34000;
		valor_adicional = 1600;
		kiloAdicional = peso - 10;
		cout <<"\nValor por cada kilo superior a 10 - $" <<valor_adicional;
	}
	if (peso >=50)
	{
		cargo_fijo = 60000;
		valor_adicional = 1900;

		kiloAdicional = peso - 50;
		cout <<"\nValor por cada kilo superior a 50 - $" <<valor_adicional;
	}

	/* calcula valor adicional */
	valor_adicional *= kiloAdicional;

	/* Muestra valores resultado */
	cout <<"\nKilo adicional: " <<kiloAdicional <<" Kg\n";
	cout <<"Valor adicional: $" <<valor_adicional <<'\n';
	cout <<"Cargo de Envio: $" <<cargo_fijo <<'\n';

	/* calcula costo total a pagar por envio */
	costo = cargo_fijo + valor_adicional;
}
/**
 * mensaje_inicio - muestra el monto a pagar
 */
void mensaje_final(double costo)
{
	cout <<"\n*****************************************\n";
	cout <<"El costo total del envio: $" <<costo;
	cout <<"\n*****************************************\n";
}
