#if !defined(_PVENTAS_H_)
#define _PVENTAS_H_

#include "Empleado.h"

/* Clase Promedio Ventas */
class PVentas: public Empleado
{
    /* Atributos de la clase */
    private:
        int * Meses;
        unsigned int NMeses;

    protected:
        /* Asignacion memoria */
        int * setMemoria(unsigned int);

    public:
        /* Constructor */
        PVentas();
        /* Destructor */
        ~PVentas();
        /* Metodos */
        /*
         * setMes - asigna un valor a cada elemento del arreglo
         * elemento: valor por mes
         * i: numero indice
         */
        void setMes(int, unsigned int);
        /*
         * getMes - obtiene valor del me deacuerdo al indice
         * i: indice
         */
        int getMes(unsigned int) const;
        /*
         * numeroElementos - obtiene el largo del arreglo
         */
        int numeroElementos() const;
        /*
         * calcularPromedio - genera un promedio por empleado
         */
        double calcularPromedio();
        /*
         * visualizar - muestra cada elemento del arreglo
         */
        void Visualizar();
};

#endif /* _PVENTAS_H_ */