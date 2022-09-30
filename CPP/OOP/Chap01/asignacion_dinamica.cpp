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

int main() {
    int * ptrint = new int;
    matriz2d m;
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
    LeerMatriz(m);
    MostrarMatriz(m);
    DestruirMatriz(m);
    std::cout <<std::endl;

    delete ptrint;

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