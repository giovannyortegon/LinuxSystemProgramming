#ifndef _MATRIZ2D_H_
#define _MATRIZ2D_H_

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

#endif /* _MATRIZ2D_H_ */
