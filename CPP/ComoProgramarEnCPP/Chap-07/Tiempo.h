#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
private:
    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;

public:
    Tiempo();
    void establecerTiempo(int, int, int);
    void imprimirUniversal() const;
    void imprimirEstandar() const;
    // Tiempo(/* args */);
    // ~Tiempo();
};


#endif /* TIEMPO_H */