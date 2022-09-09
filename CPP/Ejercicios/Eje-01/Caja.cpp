#include<iostream>

class Caja {
    private:
        int alto;
        int ancho;
        int profundo;

    public:
        Caja();
        Caja(int al, int an, int pro);
        void CalcularVolumen();
};
Caja::Caja():alto(0), ancho(0), profundo(0) {}

Caja::Caja(int al, int an, int pro) {
    this->alto= al;
    this->ancho = an;
    this->profundo = pro;
}
void Caja::CalcularVolumen() {
    int result = this->alto * this->ancho * this->profundo;

    std::cout <<result <<std::endl;
}

int main() {
    Caja c1(10, 10, 10);
    c1.CalcularVolumen();

    Caja c2;

    c2.CalcularVolumen();

}