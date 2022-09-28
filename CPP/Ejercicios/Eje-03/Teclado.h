/*
 * TECLADO_H
 */
#ifndef _TECLADO_H_
#define _TECLADO_H_

#include"DispositivosEntrada.h"

class Teclado: protected DispositivoEntrada {
    private:
        int idTeclado;

    public:
        Teclado();
        Teclado(std::string, std::string);
        ~Teclado();

        static int cont;
        static int counter();

        void Print();
};

#endif /* _TECLADO_H_ */
