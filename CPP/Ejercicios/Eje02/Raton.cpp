#include "Raton.h"
#include "DispositivosEntrada.h"

int Raton::cont = 0;

Raton::Raton() {
}
Raton::Raton(std::string tipoEntrada, std::string marca):DispositivoEntrada(tipoEntrada, marca) {
    Raton::counter();
    this->idRaton = cont;
}
Raton::~Raton() {}
void Raton::counter() {
    Raton::cont++;
}
void Raton::Print() {
    std::cout <<"Id: " <<idRaton <<" Tipo de Entrada: " <<getTipoEntrada() <<" Marca: "<<getMarca();
    std::cout <<std::endl;
}