#if !defined(_REPTIL_H_)
#define _REPTIL_H_
#include "Inicio.h"

// Clase derivada de Inicio
class Reptil: public Inicio
{
    // Atributos
	private:
        string tipo_escamas;
		
	public:
        // Constructor
		Reptil(string nom, string t, string t_sang, string es);
        // Metodos
        void setEscamas(string es);
        string getEscamas() const;		
};

#endif // _REPTIL_H_