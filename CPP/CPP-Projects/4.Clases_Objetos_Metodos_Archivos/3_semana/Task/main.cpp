#include "PVentas.h"
#include<iomanip>
#include<conio.h>

/*
 * main - punto de entrada
 */
int main(void)
{
    /* Declaracion e Inicializacion de Variables
     * cant - numero de empleados
     * valor - toma el valor de venta del mes
     * Promedio - almacena promedio de ventas
     * TotalPromedio - almacena la operacion del promedio de todos los empleados
     */
    int cant = 0, valor = 0, promedio = 0, TotalPromedio = 0;
    string nombre;      // Variable tipo string para ingresar nombre empleado.

    /* Titulo de Entrada */
    cout <<"\n***********************************\n";
    cout <<"******** CALCULAR PROMEDIO ********";
    cout <<"\n***********************************\n";    

    /* Pregunta la cantidad de vendedores a promediar */
    cout <<"\nDe Cuantos vendedores desea ver el promedio: ";
    cin >>cant;

    /* Instancia del Objeto emplado  */
    PVentas * empleado = new PVentas[cant];

    /* Bucle para Ingresar cliente y valores por mes */
    cout <<"\nIntroduzca el nombre de los Empleados y Totalidad por Mes:\n";
    for (int i = 0; i < cant; i++)
    {
        cout <<"\nEmpleado " <<i + 1;
        cout <<"\nNombre: ";
        cin >>nombre;               // Ingresa nombre
        empleado[i].setNombre(nombre);

        /* Bucle que permite ingresar valor de ventas mensual */
        for (int j = 0; j < empleado[i].numeroElementos(); j++)
        {
            cout <<"Mes " <<j + 1 <<": $";
            cin >>valor;                    // valor de ventas mensual
            empleado[i].setMes(valor, j);
        }
        cout <<"\n";
    }

    /* Titulo del Reporte */
    cout <<"\n***********************************\n";
    cout <<"************* REPORTE *************";
    cout <<"\n***********************************\n";

    /* Bucle para generar reporte tambien calcula Promedio Total */
    for (int i = 0; i < cant; i++)
    {
        cout <<"\nNombre empleado: " <<i + 1 <<"\n";
        cout <<empleado[i].getNombre() <<"\n";
        cout <<"Datos de Venta de " <<empleado[i].numeroElementos() <<" Meses\n";
        empleado[i].Visualizar();               // Muestra informe por empleado
        cout <<endl;

        /* Muestra promedio por empelado */
        promedio = empleado[i].calcularPromedio();
        cout <<"Promedio de Venta: $";
        cout <<setw(2) <<promedio;

        /* Calcula promedio Total */
        if (cant > 1)
            TotalPromedio += promedio;
        else
            TotalPromedio = promedio;
    }

    /* Imprime Promedio Total */
    cout <<"\n\n**********************************\n";
    cout <<"* Promedio Total Venta: $";
    cout <<setw(2) <<TotalPromedio / cant <<" *";
    cout <<"\n**********************************\n";

    /* Elimina contenido del puntero empleado */
    delete [] empleado;
    getch();   // Permite generar una pausa en el programa

    /* Finaliza Exitosamente */
    return (0);
}