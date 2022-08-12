#include<iostream>

using namespace std;
/*
 * main - Calcula el area de un Rombo
 */
int main(void)
{
    float area, diagonalMayor, diagonalMenor;
// Solicitud de informacion al usuario
    cout <<"ENCONTRAR EL AREA DE UN ROMBO" <<endl <<endl;
    cout <<endl <<"Ingrese la diagonal Mayor: " <<endl <<endl;
    cin >>diagonalMayor;
    cout <<endl <<"Ingrese la diagonal menor: " <<endl <<endl;
    cin >>diagonalMenor;
// Calcula el area
    area = (diagonalMayor * diagonalMenor) / 2;
// Limpia pantalla
    system("cls");
// Imprime el resultado del area
    cout <<"ROMBO" <<endl <<endl;
    cout <<"Su area es: " << area <<endl <<endl;  
// Pausa para visualizar el contenido de la terinal   
    system("pause");
// Salida exitosa
    return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
