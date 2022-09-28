#include"Teclado.h"
#include"DispositivosEntrada.h"

int Teclado::cont = 1;

Teclado::Teclado() {}
Teclado::Teclado(std::string tipoEntrada, std::string marca):DispositivoEntrada(tipoEntrada, marca) {
    this->idTeclado = Teclado::counter();
}
Teclado::~Teclado() {}
int Teclado::counter() {
    return Teclado::cont++;
}
void Teclado::Print() {
    std::cout <<"Id: " <<this->idTeclado <<" Tipo de Entrada: " <<getTipoEntrada() <<" Marca: "<< getMarca() <<std::endl;
}