#include<iostream>

using namespace std;

class Articulo
{
    private:
        int clave;
        int existencia;
        double precio;

    public:
        Articulo();
        double getPrecio();
        int getClave();
        int getExistencia();
        void inicializa(int, int, double);
        void registraEntrada(int cant);
        int registraSalida(int cant);
};
