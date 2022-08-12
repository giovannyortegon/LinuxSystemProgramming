#if !defined(_MAMIFERO_H_)
#define _MAMIFERO_H_

#include"Inicio.h"

// Clase derivada de Inicio
class Mamifero: public Inicio
{
    // Atributos
	private:
		int gestacion;

	public:
		// Constructor
		Mamifero(string nom, string t, string t_sang, int gest); // constructor con argumentos
		// Metodos	
		void setGestacion(int gest);
        int getGestacion() const;
};

#endif //_MAMIFERO_H_