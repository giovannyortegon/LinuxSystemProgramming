#include<iostream>
#include<algorithm>

struct matriz2d {
    double **p;
    int filas;
    int cols;
};

bool ConstruirMatriz(matriz2d &m);
void DestruirMatriz(matriz2d &m);
void LeerMatriz(matriz2d &m);
void MostrarMatriz(matriz2d m);
int CrearMenu(const char * opMenu[], int num_opciones);

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

int CrearMenu(const char * opMenu[], int num_opciones) {
    int opcion;

    std::cout <<"\nElija una opcion:\n" <<std::endl;
    for (int i = 0; i < num_opciones; i++) {
        std::cout <<"\t" << i + 1 <<". " <<opMenu[i] <<std::endl;
    }

    // elegir una opcion
    std::cout <<">> "; std::cin >>opcion;

    if (opcion < 1 || opcion > num_opciones) {
        std::cout <<"Opcion incorrecta\n";
    }

    return opcion;
}

bool ConstruirMatriz(matriz2d &m) {

    m.p = (double **) new (std::nothrow) double * [m.filas];
    if (m.p == nullptr) return false;
    std::fill(m.p, m.p + m.filas, nullptr);

    for (int f = 0; f < m.filas; f++) {
        m.p[f] = (double *)new (std::nothrow) double [m.cols];
        if (m.p == nullptr) {
            DestruirMatriz(m);
            return false;
        }
        std::fill(m.p[f], m.p[f]+m.cols, 0);
    }
    return true;
}
void DestruirMatriz(matriz2d &m) {
    if (m.p == nullptr) return;
    for (int f = 0; m.p[f] == nullptr && f < m.filas; f++)
        delete [] m.p[f];
    delete [] m.p;
    m.p = nullptr;
    std::cout <<"\nEliminado" <<std::endl;

}
void LeerMatriz(matriz2d &m) {
    if (m.p == nullptr) return;
    for(size_t f = 0; f < m.filas; f++) {
        for(size_t c = 0; c < m.cols; c++) {
            std::cout <<"m[" <<f <<"]["<<c <<"]: ";
            std::cin >> m.p[f][c];
        }
    }
}
void MostrarMatriz(matriz2d m) {
    if (m.p == nullptr) return;
    for(size_t f = 0; f < m.filas; f++) {
        for(size_t c = 0; c < m.cols; c++) {
            std::cout <<" m[" <<f <<"]["<<c <<"]: " << m.p[f][c];
        }
        std::cout<<std::endl;
    }
}