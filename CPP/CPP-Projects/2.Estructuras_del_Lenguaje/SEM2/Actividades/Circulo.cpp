#include<iostream>
#include<math.h>

#define PI 3.1415926535

using namespace std;
/*
 * main - Calcula el Area de un circulo
 */
int main(void)
{
    float area, radio;
// Solicitud de informacion al usuario
    cout <<"ENCONTRAR EL AREA DE UN CIRCULO" <<endl <<endl;
    cout <<endl <<"Ingrese el radio: " <<endl <<endl;
    cin >>radio;
// Calcula el area
    area = PI * pow(radio, 2);
// Limpia pantalla
    system("cls");
// Imprime el resultado del area
    cout <<"CIRCULO" <<endl <<endl;
    cout <<"Su area es: " << area <<endl <<endl;  
// Pausa para visualizar el contenido de la terinal   
    system("pause");
// Salida exitosa
    return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
