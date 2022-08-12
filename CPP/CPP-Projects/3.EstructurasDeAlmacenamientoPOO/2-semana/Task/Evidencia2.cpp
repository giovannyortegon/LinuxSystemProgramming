#include<iostream>
#include<conio.h>

/* constante del maximo largo del arreglo */
#define MAX 100

using namespace std;

/* Prototipo de funciones para:
 * Crear lista
 * Visualizar lista
 */
void crear_lista(string *lista, const int cantidad);
void lista_productos(string lista[], const int cantidad);
/*
 * main - Punto de entrada 
 */
int main(void)
{
    /* Definicion e Inicializacion de variables */
    char continuar = 'S';       // Variable tipo char para definir si genera o no una lista nueva.
    int cantidad;               // Variable tipo entero para definir la cantindad de productos a ingresar.
    string productos[MAX];      // Arreglo tipo string para crear lista de productos.

    /* Mensaje de inicio del programa */
    cout <<"\n*****************************************" <<endl;
    cout <<"*\t\tCREAR LISTA\t\t*" <<endl;
    cout <<"*****************************************" <<endl;

    /* Bucle while para ingreso de los productos */
    while (1)
    {
        cout <<"Cuantos productos desea agregar? ";
        cin >>cantidad;
        cout <<"\n";
        /* Se llama la funcion crear lista que tomados argumentos para crear una lista
         * Primer argumento: arreglo tipo string llamado productos.
         * Sengundo arguemnto: la cantidad de productos que desea ingresar a la lista.
         */
        crear_lista(productos, cantidad);

        cout <<"\nEsta satisfecho con la lista o desea generar una nueva? (S/N)\n";
        cin >>continuar;        // variable tipo char para continuar o salir del ciclo.

        /* Sentencia que define si crear o no una lista nueva */
        if (continuar == 'S' || continuar == 's')
            break;             // Finaliza el bucle
        else
            cout <<"Vamos a crear una lista nueva\n";
    }

    cout <<"\nHa Finalizado la lista.\nEstos son los productos de lista.\n\n";
    /* Visualiza los productos seleccionados, contine 2 argumentos:
     * Primer argumento: arreglo tipo string para listar productos
     * Segundo argumento: variable tipo entero que es la cantidad de productos a ingresar
     */
    lista_productos(productos, cantidad);

    /* Mensaje finalizacion del programa */
    cout <<"\n*****************************************" <<endl;
    cout <<"************ Lista Finalizada ***********\n";
    cout <<"*****************************************" <<endl;
    
    getch();
    return (0); /* Finaliza el programa exitosamente */
}
/*
 * crear_lista - Permite generar una lista de productos
 * lista - puntero a un arreglo
 * cantidad - largo del arreglo
 */
void crear_lista(string *lista, const int cantidad)
{
    int i = 0;

    cout <<"|    Producto #    |    Producto    |\n";

    /* Buclea que permite ingresar el prducto uno a uno */
    while (i < cantidad)
    {
        cout <<'\t' <<i + 1 <<"\t\t";
        cin >>lista[i];                 // Solicita ingresar producto
        i++;
    }
}
/*
 * lista_productos - Permite visulizar una lista de productos
 * lista - copia del arreglo de lista de productos
 * cantidad - largo del arreglo
 */
void lista_productos(string lista[], const int cantidad)
{
    int i = 0;

    cout <<"|    Producto #    |    Producto    |\n";

    /* Producto que permite visualizar cada uno de los productos */
    while(i < cantidad)
    {
        cout <<'\t' <<i + 1 <<"\t\t";
        cout <<lista[i];                   // Imprime producto
        cout <<'\n';
        i++;
    }
}