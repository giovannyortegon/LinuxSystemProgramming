#include<iostream>

class ClassA {
    public:
        int atributo_x;

    public:
        ClassA(int x =1):atributo_x{x} {}

        int metodo_x() {
            return atributo_x * 10;
        }

        int metodo_y() {
            return atributo_x + 100;
        }
};

class ClassB : public ClassA {
    public:
        int atributo_x;

    public:
        ClassB(int x = 2) : atributo_x {x} {}
        int metodo_x() {
            return atributo_x * -10;
        }
};

int main() {
    ClassB objClassB;

    std::cout <<objClassB.atributo_x <<std::endl;   // escribe 2
    std::cout <<objClassB.metodo_y() <<std::endl;   // escribe 101
    std::cout <<objClassB.metodo_x() <<std::endl;   // escribe -20

    return (0);
}