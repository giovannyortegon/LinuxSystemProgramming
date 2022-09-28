#ifndef __RATON__
#define __RATON__

#include "DispositivosEntrada.h"

class Raton: protected DispositivoEntrada {
    private:
        int idRaton;

    public:
        Raton();
        Raton(std::string tipoEntrada, std::string marca);
        ~Raton();

        static int cont;
        static int counter();

        void Print();
};

#endif /* __RATON__*/