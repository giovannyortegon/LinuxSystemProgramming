#include<iostream>
#include<algorithm>
#include"matriz2d.h"

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
