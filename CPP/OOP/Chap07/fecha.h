/*
 * fecha.h
 */
#ifndef __FECHA_H
#define __FECHA_H__

class CFecha {
    private:
        int dia, mes, anyo;

    protected:
        bool anyoBisiesto(int aaaa);
        bool fechaValida(int dd, int mm, int aaaa);

    public:
        // CFecha();
        bool asignarFecha();
        bool asignarFecha(int dd);
        bool asignarFecha(int dd, int mm);
        bool asignarFecha(int dd, int mm, int aaaa);
        void obtenerFecha(int & dd, int & mm, int & aaaa);
        void obtenerFechaActual(int &dd, int &mm, int &aaaa);

};

#endif /* __FECHA_H__ */
