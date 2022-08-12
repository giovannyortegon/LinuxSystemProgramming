#if !defined(_INICIO_H_)
#define _INICIO_H_

#include <iostream>
#include <conio.h>

using namespace std;
// Clse Base
class Inicio
{
	// Atributos
	private:
		string nombre;
		string tipo;
		string tipo_sangre;
		
	public:
		// Constructor
		Inicio(string nom, string t, string t_sang);
		// Metodos
		void setNombre(string nom);
		string getNombre() const;
		void setTipo(string t);
		string getTipo() const;
		void setTipoSangre(string t_sang);
		string getTipoSangre() const;
};

#endif // _CUENTA_H_