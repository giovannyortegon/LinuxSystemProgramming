#include<iostream>
#include"matriz2d.h"

int main() {
    int opcion = 0;
    static const char * opciones[] = {
        "Construir matriz",
        "Leer matriz",
        "Mostrar matriz",
        "Destruir matriz",
        "Finalizar"
    };

    const int num_opciones = sizeof(opciones)/ sizeof(char *);
    matriz2d m {nullptr, 0, 0};

    do {
        opcion = CrearMenu(opciones, num_opciones);
        enum op { Construir = 1, Leer, Mostrar, Destruir, Finalizar };

        switch (opcion) {
            case Construir:
                if (m.p != nullptr) {
                    std::cout <<"Ya existe una matriz. Destruyala para crear otra.\n" <<std::endl;
                    break;
                } 
                do {
                    std::cout <<"Ingrese numero de filas: "; std::cin >>m.filas;
                } while(m.filas < 1);

                do {
                    std::cout <<"Ingrese numero de columnas: "; std::cin >>m.cols;
                } while(m.cols < 1);
                
                if (!ConstruirMatriz(m)) {
                    std::cout <<"No se pudo construir la matriz" <<std::endl;
                    return (-1);
                }
                std::cout <<"\nMatriz construida.\n" <<std::endl;
                break;
            case Leer:
                if (m.p == nullptr)
                    std::cout <<"No existe una matriz.\n";
                else
                    LeerMatriz(m);
                break;
            case Mostrar:
                if (m.p == nullptr)
                    std::cout <<"No existe una matriz.\n";
                else
                    MostrarMatriz(m);
                break;
            case Destruir:
                if (m.p == nullptr)
                    std::cout <<"No existe una matriz.\n";
                else {
                    DestruirMatriz(m);
                    std::cout <<"Matriz destruida.\n" <<std::endl;
                }
                break;

            case Finalizar:
                if (m.p != nullptr) DestruirMatriz(m);
                break;
        }
    } while (opcion != num_opciones);

    std::cout <<std::endl;

    return (0);
}