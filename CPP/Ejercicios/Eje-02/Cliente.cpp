#include"Cliente.h"
#include<ctime>

time_t now = time(0);
int Cliente::constador = 0;

Cliente::Cliente() {
    this->idCliente = ++Cliente::constador;
    this->date = ctime(&now);
}
Cliente::Cliente(const Cliente &c) {
    this->idCliente = ++Cliente::constador;
    this->date = ctime(&now);
}
Cliente::Cliente(std::string nom, char gen, int ed, std::string dir, bool vip)
: Persona(nom, gen, ed, dir) {
    this->idCliente = ++Cliente::constador;
    this->date = ctime(&now);
    this->vip = vip;
}
std::string Cliente::Print() {
    std::string c_vip = this->vip ? "true" : "false";
    return "Cliente { Id: " + std::to_string(this->idCliente) + " Nombre: " + this->nombre + " Genero: " + this->genero +
            " Edad: " + std::to_string(this->edad) + " Direccion: " + this->direccion + " fecha: " + this->date +
            " VIP: " + c_vip + " }";
}

Cliente::~Cliente() {}