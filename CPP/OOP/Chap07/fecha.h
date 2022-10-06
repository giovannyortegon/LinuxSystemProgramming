/*
 * fecha.h
 */
#ifndef __FECHA_H
#define __FECHA_H__

class CFecha {
    private:
        int dia, mes;
        long anyo;

    protected:
        bool anyoBisiesto(long aaaa);
        bool fechaValida(int dd, int mm, long aaaa);

    public:
        bool asignarFecha();
        bool asignarFecha(int dd);
        bool asignarFecha(int dd, int mm);
        bool asignarFecha(int dd, int mm, long aaaa);
        void obtenerFecha(int &dd, int &mm, long &aaaa);

};

#endif /* __FECHA_H__ */
