#ifndef __CUENTA_CORRIENTE_PLUS__
#define __CUENTA_CORRIENTE_PLUS__

#include"cuenta_corriente.h"

class CCuentaCorrientePlus : public CCuentaCorriente {

    public:
        CCuentaCorrientePlus(std::string nom = "sin nombre", std::string cue = "0000", double sal = 0.0,
                             double tipo = 0.0, double imptrans = 0.0, int transex = 0);
        ~CCuentaCorrientePlus();
        double intereses();
};

#endif /* __CUENTA_CORRIENTE_PLUS__ */