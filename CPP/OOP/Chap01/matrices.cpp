#include<iostream>
#include<vector>

using namespace std;

vector<vector<double>> ConsttruirMatriz(int nFilas, int nColumna); 
void LeerMatriz(vector<vector<double>> &m);
void MostrarMatriz(vector<vector<double>> &m);

int main() {
    int filas, cols;
    cout <<"No de filas de la matriz: "; cin >>filas;
    cout <<"No de columnas de la matriz: "; cin >> cols;
    vector<vector<double>> m = ConsttruirMatriz(filas, cols);
    LeerMatriz(m);
    MostrarMatriz(m);

    cout <<endl;

    return (0);
}

vector<vector<double>> ConsttruirMatriz(int nFilas, int nColumna) {
    vector<vector<double>> v(nFilas, vector<double>(nColumna, 0));
    return v;
}

void LeerMatriz(vector<vector<double>> &m) {
    for (size_t f = 0; f < m.size(); ++f) {
        for (size_t c = 0; c < m[f].size(); ++c) {
            cout <<"m[" <<f <<"][" <<c << "]:";
            cin >> m[f][c];
        }
    }
}

void MostrarMatriz(vector<vector<double>> &m) {
    for (auto v : m) {
        for (auto e : v) {
            cout <<e <<" ";
        }
        cout <<endl;
    }
}