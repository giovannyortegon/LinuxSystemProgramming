#include<iostream>
#include<stdlib.h>

using namespace std;

class Persona
{
    private:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        virtual void ver();
};

class Empleado: public Persona
{
    private:
        string cargo;
    public:
        Empleado(string, int, string);
        void ver();
};

class Socio: public Persona
{
    private:
        int porcentaje;
    public:
        Socio(string, int, int);
        void ver();
};

Persona::Persona(string elNombre, int laEdad)
{
    nombre = elNombre;
    edad = laEdad;
}
void Persona::ver()
{
    cout <<"Nombre: " <<nombre <<endl;
    cout <<"Edad: " <<edad <<endl;

}
Empleado::Empleado(string elNombre, int laEdad, string elCargo)
:Persona(elNombre, laEdad)
{
    cargo = elCargo;
}
void Empleado::ver()
{
    Persona::ver();
    cout <<"Cargo: " <<cargo <<endl;
}
Socio::Socio(string elNombre, int laEdad, int elPorcentaje)
:Persona(elNombre, laEdad)
{
    porcentaje = elPorcentaje;
}

void Socio::ver()
{
    Persona::ver();
    cout <<"Porcentaje: " <<porcentaje <<endl;
}

int main()
{
    Socio socio1 = Socio("Andres Herrera", 43, 51);
    Persona persona1 = Persona("Camila Soto", 19);

    socio1.ver();
    persona1.ver();

    return (0);
}
