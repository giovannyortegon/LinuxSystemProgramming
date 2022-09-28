#include "Raton.h"
#include "DispositivosEntrada.h"

int Raton::cont = 1;

Raton::Raton() {
}
Raton::Raton(std::string tipoEntrada, std::string marca):DispositivoEntrada(tipoEntrada, marca) {
    this->idRaton = Raton::counter();
}
Raton::~Raton() {}
int Raton::counter() {
    return Raton::cont++;
}
void Raton::Print() {
    std::cout <<"Id: " <<idRaton <<" Tipo de Entrada: " <<getTipoEntrada() <<" Marca: "<<getMarca();
    std::cout <<std::endl;
}