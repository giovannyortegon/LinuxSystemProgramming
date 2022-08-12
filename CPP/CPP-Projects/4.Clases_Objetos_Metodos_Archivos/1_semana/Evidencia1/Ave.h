#if !defined(_AVE_H_)
#define _AVE_H_
#include "Inicio.h"

// Clase derivada de Inicio
class Ave: public Inicio
{
		// Atributos
	private:
		string color_plumas;
	public:
		// Constructor
        Ave(string nom, string t, string t_sang, string c_plumas);
		// Metodos
        void setPlumas(string c_plumas);
        string getPlumas() const;
};

#endif