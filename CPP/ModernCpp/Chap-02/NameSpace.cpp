#include<iostream>

namespace hola {
    void print() {
        std::cout <<"Hola a todos!!" <<std::endl;
    }
}
namespace saludo {
    void print() {
        std::cout <<"Un saludo a todos!!" <<std::endl;
    }
}

int main() {
    hola::print();
    saludo::print();

    return(0);
}