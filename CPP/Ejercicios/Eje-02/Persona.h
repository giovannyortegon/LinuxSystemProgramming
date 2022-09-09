#ifndef __PERSONA__
#define __PERSONA__

#include<iostream>
#include<string>

class Persona {


    public:
        Persona();
        Persona(const Persona &p);
        Persona(std::string nom, char gen, int ed, std::string dir);
        ~Persona();
        std::string Print() const;

    protected:
        std::string nombre;
        char genero;
        int edad;
        std::string direccion;

        std::string getNombre() const;
        void setNombre(std::string nom);
        char getGenero() const;
        void setGenero(char gen);
        int getEdad() const;
        void setEdad(int ed);
        std::string getDireccion() const;
        void setDireccion(std::string dir);

};

#endif /* __PERSONA__ */