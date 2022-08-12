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
        void verPersona();
};
class Empleado :public Persona
{
    private:
        string cargo;
        float salario;
    public:
        Empleado(string, int, string, float);
        void verEmpleado();
};

Persona::Persona(string elNombre, int laEdad)
{
    nombre = elNombre;
    edad = laEdad;
}

Empleado::Empleado(string elNombre,int laEdad,string elCargo,float elSalario)
:Persona(elNombre, laEdad)
{
    cargo = elCargo;
    salario = elSalario;
}
void Empleado::verEmpleado()
{
    verPersona();
    cout <<"Cargo: " <<cargo <<endl;
    cout <<"Salario: " <<salario <<endl;
}
void Persona::verPersona()
{
    cout <<"Nombre: " <<nombre <<endl;
    cout <<"Edad: " <<edad <<endl;
}
int main()
{
    Empleado empleado1 = Empleado("Camila Soto", 19, "Recepcionista", 890000);

    empleado1.verEmpleado();

    return (0);
}
