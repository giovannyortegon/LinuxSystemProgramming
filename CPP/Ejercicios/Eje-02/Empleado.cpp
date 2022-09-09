#include"Empleado.h"
#include"Persona.h"

int Empleado::contador = 0;

Empleado::Empleado() {}
Empleado::Empleado(const Empleado &e) {}
Empleado::Empleado(std::string nom, char gen, int ed, std::string dir, int sueldo)
:Persona(nom, gen, ed, dir) {
    this->idEmpleado= ++Empleado::contador;
    this->sueldo = sueldo;
}
Empleado::~Empleado() {}

std::string Empleado::Print() {
    // return "Id: " + std::to_string(idEmpleado) + " " +Persona::Print() + " sueldo: " + std::to_string(sueldo);
    return "Empleado { Id: " + std::to_string(idEmpleado) + " Nombre: " + this->nombre + " Genero: " + 
                this->genero + " Edad: " + std::to_string(this->edad) + " Direccion: " + this->direccion +
                " Sueldo: " + std::to_string(sueldo) + " }";
}