#include "Inicio.h"
#include "Mamifero.h"
#include "Ave.h"
#include "Reptil.h"

/*
 * main - punto de entrada
 */
int main(int argc, char** argv)
{
	// Declaracion e Inicialización
	Inicio mascota("Perro", "Mamifero", "Caliente");
    Mamifero salvaje("Leon", "Mamifero", "Caliente", 108);
    Ave pajaro("Paloma", "Bipedo", "Caliente", "Gris");
    Reptil reptil("Lagarto","Reptil", "Fria", "Gruesas"); 

    // Imprime datos ingresados
	cout <<"Nombre animal: " <<mascota.getNombre();
	cout <<endl <<"Tipo Animal: " <<mascota.getTipo();
	cout <<endl <<"Tipo Sangre: " <<mascota.getTipoSangre();
    cout <<endl;
	cout <<endl <<"Nombre animal: " <<salvaje.getNombre();
	cout <<endl <<"Tipo Animal: " <<salvaje.getTipo();
	cout <<endl <<"Tipo Sangre: " <<salvaje.getTipoSangre();
    cout <<endl <<"Tiempo gestacion: " <<salvaje.getGestacion();
    cout <<endl;
    cout <<endl <<"Nombre animal: " <<pajaro.getNombre();
	cout <<endl <<"Tipo Animal: " <<pajaro.getTipo();
	cout <<endl <<"Tipo Sangre: " <<pajaro.getTipoSangre();
    cout <<endl <<"Color Plumas: " <<pajaro.getPlumas();
    cout <<endl;
    cout <<endl <<"Nombre animal: " <<reptil.getNombre();
	cout <<endl <<"Tipo Animal: " <<reptil.getTipo();
	cout <<endl <<"Tipo Sangre: " <<reptil.getTipoSangre();
    cout <<endl <<"Tipo de Escamas: " <<reptil.getEscamas();
    cout <<endl;

    getch(); // Pausa el programa
	return (0); // Finaliza el programa exitosamente
}