#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include "Persona.h"

class Cliente :Persona {
private:
    int idCliente;
    std::string date;
    bool vip;

public:
    static int constador;
    Cliente();
    Cliente(std::string nom, char gen, int ed, std::string dir, bool vip);
    Cliente(const Cliente &c);
    ~Cliente();
    std::string Print();
};

#endif /* __CLIENTE_H__ */