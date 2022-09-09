#ifndef __DispositivosEntrada__
#define __DispositivosEntrada__

#include<iostream>

class DispositivoEntrada {
    protected:
        std::string tipoEntrada;
        std::string marca;

    public:
        DispositivoEntrada();
        DispositivoEntrada(std::string tipo, std::string marca);
        ~DispositivoEntrada();

        std::string getMarca() const;
        void setMarca(std::string ma);
        std::string getTipoEntrada() const;
        void setTipoEntrada(std::string ten);
        void Print();
};

#endif /* __DispositivoEntrada__ */