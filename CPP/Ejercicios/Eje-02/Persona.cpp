#include"Persona.h"


Persona::Persona() {}
Persona::Persona(const Persona &p) {}
Persona::Persona(std::string nom, char gen, int ed, std::string dir){
    this->nombre = nom;
    this->genero = gen;
    this->edad = ed;
    this->direccion = dir;
}
Persona::~Persona() {}

std::string Persona::getNombre() const {
    return this->nombre;
}
void Persona::setNombre(std::string nom) {
    this->nombre = nom;
}
char Persona::getGenero() const {
    return this->genero;
}
void Persona::setGenero(char gen) {
    this->genero = gen;
}
int Persona::getEdad() const {
    return this->edad;
}
void Persona::setEdad(int ed) {
    this->edad = ed;
}
std::string Persona::getDireccion() const {
    return this->direccion;
}
void Persona::setDireccion(std::string dir) {
    this->direccion = dir;
}
std::string Persona::Print() const {
    return "Persona: { nombre: " + this->nombre + " Genero: " + this->genero + " Edad: " +  std::to_string(this->edad) + " Direccion: " + this->direccion + " } ";
}