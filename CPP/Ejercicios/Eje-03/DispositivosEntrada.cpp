#include "DispositivosEntrada.h"

DispositivoEntrada::DispositivoEntrada() { }
DispositivoEntrada::DispositivoEntrada(std::string tipo, std::string ma)
:tipoEntrada(tipo), marca(ma) {
}
DispositivoEntrada::~DispositivoEntrada() { }

std::string DispositivoEntrada::getMarca() const {
    return this->marca;
}
void DispositivoEntrada::setMarca(std::string ma) {
    this->marca = ma;
}
std::string DispositivoEntrada::getTipoEntrada() const {
    return this->tipoEntrada;
}
void DispositivoEntrada::setTipoEntrada(std::string ten) {
    this->tipoEntrada;
}
void DispositivoEntrada::Print() {
    std::cout <<"Tipo de Entrada: " <<this->tipoEntrada <<" Marca: "<<this->marca <<std::endl;
}
