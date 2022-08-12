#if !defined(_NUMEROIRRACIONAL_H_)
#define _NUMEROIRRACIONAL_H_

#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include<cstring>


using namespace std;

/* Clase para realizar operaciones con numeros imaginarios */
class NumeroIrracional
{
	// Atributos
	private:
		double entera;
		double imaginaria;

	// Metodos
	public:
		NumeroIrracional();
		NumeroIrracional(double, double);
		~NumeroIrracional();
		string Mostrar();
		string take_time();

	// funciones Friend para sobrecargar los operadores
	friend NumeroIrracional operator + (NumeroIrracional, NumeroIrracional);
	friend NumeroIrracional operator - (NumeroIrracional, NumeroIrracional);
	friend NumeroIrracional operator * (NumeroIrracional, NumeroIrracional);
	friend NumeroIrracional operator / (NumeroIrracional, NumeroIrracional);
};

#endif /* _NUMEROIRRACIONAL_H_ */
