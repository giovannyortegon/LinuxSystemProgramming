#include<iostream>

using namespace std;
/*
 * main - Calcula el area del Trapecio
 */
int main(void)
{
    float area, baseMayor, baseMenor, altura;
// Solicitud de informacion al usuario
    cout <<"ENCONTRAR EL AREA DE UN TRAPECIO" <<endl <<endl;
    cout <<endl <<"Ingrese la Base Mayor: " <<endl <<endl;
    cin >>baseMayor;
    cout <<endl <<"Ingrese la Base menor: " <<endl <<endl;
    cin >>baseMenor;
    cout <<endl <<"Ingrese la altura: "<<endl;
    cin >>altura;
// Calcula el area
    area = ((baseMayor + baseMenor) / 2) * altura;
// Limpia pantalla
    system("cls");
// Imprime el resultado del area
    cout <<"TRAPECIO" <<endl <<endl;
    cout <<"Su area es: " << area <<endl <<endl;  
// Pausa para visualizar el contenido de la terinal   
    system("pause");
// Salida exitosa
    return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
