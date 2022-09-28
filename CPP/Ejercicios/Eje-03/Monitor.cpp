#include<iostream>
#include"Monitor.h"

int Monitor::count = 1;

Monitor::Monitor(){}
Monitor::Monitor(std::string marca, int tam) {
    this->idMonitor = Monitor::counter();
    this->marca = marca;
    this->tamano = tam;
}
Monitor::~Monitor() {}
int Monitor::counter(){
    return Monitor::count++;
}
void Monitor::Print() {
    std::cout <<"Id: " <<this->idMonitor <<" marca: " <<this->marca <<" tamanio: " <<this->tamano <<std::endl;
}
