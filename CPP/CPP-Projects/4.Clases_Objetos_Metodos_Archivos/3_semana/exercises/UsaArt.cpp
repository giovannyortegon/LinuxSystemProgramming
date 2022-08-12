#include<iostream>
#include"Articulo.h"

Articulo lista[30];
int tam;

void verInventario()
{
    int i;

    cout <<"La lista de articulos en el almacen es la siguiente: "<<endl;
    cout <<"\t" <<"Clave" <<"\t"<<"Cantidad en Existencia"
         <<"\t" <<"Precio" <<endl;

    for (i = 0; i < tam; i++)
    {
        cout <<"\t" <<lista[i].getClave() <<" "
             <<"\t\t\t" <<lista[i].getExistencia() <<" "
             <<"\t$" <<lista[i].getPrecio() <<endl;
    }

    cout <<endl <<endl;
}
int Busca(int cve)
{
    int i;
    int posicion = -1;  // -1 indica que no se encontro el articulo

    for (i = 0; i <tam && posicion == -1; i++)
        if (lista[i].getClave() == cve)    posicion = i;   // posicion de articulo

    return posicion;
}

void registraLlegada()
{
    int posicion, cve, cantidad;

    cout <<endl;
    cout <<"Cual es la clave del articulo" <<endl;
    cin >>cve;

    // busca la clave en el almacen
    if ((posicion = Busca(cve)) != -1)
    {
        cout <<"Cuantos articulos llegaron" <<endl;
        cin >>cantidad;
        lista[posicion].registraEntrada(cantidad);
    }
    else
        cout <<"Esa clave no existe" <<endl;

    cout <<endl;
}

void registraSalida()
{
    int posicion, cve, cantidad;

    cout <<endl;
    cout <<"Cual es la clave del articulo" <<endl;
    cin >>cve;

    // busca la clave en el almacen
    if ((posicion = Busca(cve)) != -1)
    {
        cout <<"cuantos articulos salieron" <<endl;
        cin >>cantidad;

        if (!lista[posicion].registraSalida(cantidad))
            cout <<"No hay suficientes articulos" <<endl;
    }
    else
        cout <<"Esas clave no existe" <<endl;

    cout <<endl;
}
char menu()
{
    char opc;

    cout <<endl <<endl;
    cout <<"Menu de Opciones" <<endl;
    cout <<"a. Ver el inventario" <<endl;
    cout <<"b. Registrar una llegada al almacen" <<endl;
    cout <<"c. Registrar una salida de almacen" <<endl;
    cout <<"d. Salir del programa" <<endl;

    do
    {
        cout <<"Opcion -> ";
        cin >>opc;
    } while((opc < 'a') || (opc > 'd'));

    return opc;
}

int main()
{
    int i, cve, exis;
    double pre;
    char opc;

    cout <<"cuantos articulos ";
    cin >>tam;

    for (i = 0; i < tam; i++)
    {
        cout <<"Teclea la clave para el articulo " <<i + 1 <<endl;
        cin >>cve;
        cout <<"Teclea la existencia para el articulo " <<i + 1 <<endl;
        cin >>exis;
        cout <<"Teclea el precio para el articulo " <<i + 1 <<endl;
        cin >>pre;

        lista[i].inicializa(cve, exis, pre);
    }

    do
    {
        opc = menu();

        switch(opc)
        {
            case 'a':
                verInventario();
                break;
            case 'b':
                registraLlegada();
            case 'c':
                registraSalida();
                break;
        }
    } while (opc != 'd');

    return (0);
}
