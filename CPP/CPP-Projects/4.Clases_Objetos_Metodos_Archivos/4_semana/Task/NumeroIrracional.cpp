#include "NumeroIrracional.h"

// Contructor default
NumeroIrracional::NumeroIrracional()
:entera(1), imaginaria(1){}

//constructor con dos parametros
NumeroIrracional::NumeroIrracional(double Entera, double Imaginaria)
:entera(Entera),  imaginaria(Imaginaria){}

// destructor
NumeroIrracional::~NumeroIrracional(){}

/**
 * Mostrar - Imprime Numero Irracional
 *			 parte entera e imaginaria.
 * Return	conjunto de numeros
 */
string NumeroIrracional::Mostrar()
{
	string resultado;

	cout <<"(" <<entera;	// stdout
	resultado = "(" + to_string(entera); // concatena

	if (imaginaria >= 0)
	{
		resultado += " +";	// concatena
		cout <<" +"; // stdout
	}

	cout <<" " <<imaginaria <<"i)"; // stdout
	resultado += " " + to_string(imaginaria) + "i)"; //concatena

	// retorna el log de tipo string
	return resultado;
}
/**
 * take_time - operation time
 * Return	   time for log
 */
string NumeroIrracional::take_time()
{
	int len;		// almacena largo del string
	time_t now = time(0);		// optiene hora
	char *date_now = ctime(&now); // convierte a string
	string log;

	// largo del string
	len = strlen(date_now);
	date_now[len - 1] = 0;	// elimina el caracter \n

	// concatendo
	log += "[";
	log += date_now;
	log += "] ";

	// string de tiempo dia mes hora
	return log;
}
/**
 * operator + -> sobrecarga del operado (+) suma
 * Return		suma de numeros imaginarios
 */
NumeroIrracional operator + (NumeroIrracional x, NumeroIrracional y)
{
	NumeroIrracional res;

	// operacion entre las dos expresiones
	res.entera = x.entera + y.entera;
	res.imaginaria = x.imaginaria + y.imaginaria;

	// resultado de la suma
	return (res);
}
/**
 * operator - -> sobrecarga del operado (-) resta
 * Return		resta de numeros imaginarios
 */
NumeroIrracional operator - (NumeroIrracional x, NumeroIrracional y)
{
	NumeroIrracional res;

	// operacion entre las dos expresiones
	res.entera = x.entera - y.entera;
	res.imaginaria = x.imaginaria - y.imaginaria;

	// Resultado de la resta
	return res;
}
/**
 * operator * -> sobrecarga del operado (*) multiplicar
 * Return		multiplicacion de numeros imaginarios
 */
NumeroIrracional operator * (NumeroIrracional x, NumeroIrracional y)
{
	NumeroIrracional res;

	// Operacione entre las dos expresiones
	res.entera = (x.entera * y.entera) + ((x.imaginaria * y.imaginaria)*(-1));
	res.imaginaria = (x.entera * y.imaginaria) + (x.imaginaria * y.entera);

	// resultado de la multiplicacion
	return (res);
}
/**
 * operator / -> sobrecarga del operado (/) division
 * Return		division de numeros imaginarios
 */
NumeroIrracional operator / (NumeroIrracional x, NumeroIrracional y)
{
	NumeroIrracional res, div, divr, mul;

	mul = y;
	// convierte en negativo la parte imaginaria
	mul.imaginaria = (-mul.imaginaria);
	div = x * mul;
	divr = y * mul;

	// divisor diferente de cero
	if (divr.entera == 0)
	{
		res.entera = div.entera / divr.imaginaria;
		res.imaginaria = div.entera / divr.imaginaria;
	}
	else
	{
		res.entera = div.entera / divr.entera;
		res.imaginaria = div.imaginaria / divr.entera;
	}

	// resultado de la division
	return res;
}
