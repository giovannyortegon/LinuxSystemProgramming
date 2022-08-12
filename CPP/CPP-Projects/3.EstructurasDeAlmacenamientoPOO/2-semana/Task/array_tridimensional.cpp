#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    cout <<"Bienvenido al sistema del teatro" <<endl;
    cout <<"a continuacion puede ver las salas y lugares disponibles" <<endl;

    char teatro[2][10][7];
    int sala, fila, silla, ubica;

    for (int i = 0; i < 2; i++)
    {
        cout <<"Sala numero: " <<i + 1 <<endl;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                teatro[i][j][k] = 'D';
                cout <<teatro[i][j][k];
            }
        cout <<'\n';
        } 
        cout <<'\n';
    }

    system("pause");
    system("cls");

    cout <<"Seleccione ubicacion" <<endl;
    cout <<"A cual sala de cine deasea acceder? ";
    cin >>sala;
    cout <<"En que fila desea ubicarse? ";
    cin >>fila;
    cout <<"En que silla desea ubicarse? ";
    cin >>silla;
    system("cls");
    cout <<"La ubicacion que ha elegido es ... \n";
    teatro[sala - 1][fila - 1][silla - 1] = 'X';
    cout <<"Sala " <<sala <<"en la fila " <<fila <<"silla " <<silla <<endl;
    cout <<"********************************************************" <<endl;
    
    for (int i = 0; i < 2; i++)
    {
        cout <<"Sala numero: " <<i + 1 <<endl;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                cout <<teatro[i][j][k];
            }
        cout <<'\n';
        }
        cout <<'\n';
    }
    getch();

    return (0);
}