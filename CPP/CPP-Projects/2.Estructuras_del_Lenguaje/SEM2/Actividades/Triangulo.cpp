#include<iostream>

using namespace std;
/*
 * main - Calcula el area del triangulo
 */
int main(void)
{
    float area, base, altura;
// Solicitud de informacion al usuario
    cout <<"ENCONTRAR EL AREA DE UN TRIANGULO" <<endl <<endl;
    cout <<endl <<"Ingrese la altura: " <<endl <<endl;
    cin >>altura;
    cout <<endl <<"Ingrese la base: " <<endl <<endl;
    cin >>base;
// Calcula el area
    area = (altura * base) / 2;
// Limpia pantalla
    system("cls");
// Imprime el resultado del area
    cout <<"TRIANGULO" <<endl <<endl;
    cout <<"Su area es: " << area <<endl <<endl;  
// Pausa para visualizar el contenido de la terinal   
    system("pause");
// Salida exitosa
    return EXIT_SUCCESS;
    // GIOVANNY ORTEGON
}
