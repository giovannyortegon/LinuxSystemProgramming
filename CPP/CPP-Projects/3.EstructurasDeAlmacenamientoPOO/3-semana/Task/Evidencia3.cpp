/**
 * Evidencia 3: Calcula el salario a pagar despues de Descuentos
 * Autor:       Giovanny Ortegon
*/
#include<iostream>
#include<string>
#include<iomanip>

#if defined(_WIN32)
#include<conio.h>
#endif

using namespace std;

#define MAX 255             // caracteres a extraer 
#define BUF 30              // caracteres a escribir
#define EMPLEADOS 100       // maximo de empleados a calcular
#define HORAEXTRA 6645      // equvalente a una hora extra

/* Global Variables */
/**
 * nombre -  nombre del empleado
 * cargo - ocupacion del empleado dentro de la empresaa
 */
char nombre[EMPLEADOS][BUF], cargo[EMPLEADOS][BUF];

/**
 * cadula - numero de cedula del empleado
 * telefono - numero telefonico
 * salario basico - salario del empleado
*/
int cedula[EMPLEADOS], telefono[EMPLEADOS], salario_basico[EMPLEADOS];

/**
 * HExtraT - Horas Extra modo tiempo
 * HExtraD - Horas Exrta modo Dinero
 * DXPrestamo - Descuentos por prestamo
 */
double HExtraT[EMPLEADOS], HExtraD[EMPLEADOS], DXPrestamo[EMPLEADOS];

/**
 * Ahorro - Dinero ahorrado
 * SegSocP - Porcentaje de descuento seguro social
 * SegSocD - Dinero descontado de acuerdo al porcentaje por seguro social
*/
double Ahorro[EMPLEADOS], SegSocP[EMPLEADOS], SegSocD[EMPLEADOS];

/**
 * SalarioTotal - Dinero restante despues de descuentos mas dinero ahorrado
*/
double SalarioTotal[EMPLEADOS];

/**
 * Prototipos de funciones I/O y operaciones
*/
void titulo_formulario();
void info_empleado();
void input_datos_empleados(const unsigned int);
double salario_total(const unsigned int);
void mostar_datos_empleados(const unsigned int);
double HorasExtra(double );
void DescuentoPorSeguro(double );

/**
 * main - puento de entrada
 * return: Siempre retorna 0 si finaliza exitosamente
*/
int main(void)
{
    int n_empleados;    // almacena cantidad de empleados

	cout <<"\n************************************\n";
	cout <<"******* Evidencia - Semana 3 *******";
	cout <<"\n************************************\n\n";

    /* Ingresa cantidad de empleados */
    cout <<"De cuantos empleados desea generar pagos? ";
    cin >> n_empleados;
    if (n_empleados > EMPLEADOS)
    {
        cout <<"[!] Excede la cantidad maxima.";
        exit(-1);
    }

	titulo_formulario();
	input_datos_empleados(n_empleados);     // Ingresa datos del empleado
	info_empleado();
	mostar_datos_empleados(n_empleados);    // Muestra datos del empleado

	cout <<"\n***********************************\n\n";

#if defined(_WIN32)
	getch();
#endif

	return (0); // Finalizo de forma exitosa
}

/**
 * titulo_formulario - Muestra titulo de inicio de registro
*/
void titulo_formulario()
{
	cout <<"\n***********************************\n";
	cout <<"**** Formulario datos Empleado ****";
	cout <<"\n***********************************\n";
}

/**
 * info_empleado - Imprime encabezado sobre informacion empleado
*/
void info_empleado()
{
	cout <<"\n************************************\n";
	cout <<"***** Informacion del Empleado *****";
	cout <<"\n************************************\n";
}

/**
 * input_datos_empleados - Entrada de informacion del empelado
 * n_empleado:  cantidad de empleados a calcular salario
*/
void input_datos_empleados(const unsigned int n_empleados)
{
    unsigned int i = 0;
	char SN = 'N';

    while(i < n_empleados)
    {
        cout <<"\nEmpleado " <<i + 1 <<"\n";
        cout <<"Ingrese Numero de Cedula:\n";
        cin >>cedula[i];

        cin.ignore(MAX, '\n');
        cout <<"Ingrese Nombre Completo ";
        cout <<"(Primer Nombre y Primer Apellido):\n";
        cin.getline(nombre[i], BUF);

        cout <<"Ingrese Numero telefonico:\n";
        cin >>telefono[i];

        cin.ignore(MAX, '\n');
        cout <<"Ingrese cargo: ";
        cin.getline(cargo[i], BUF);

		cout <<"Ingrese Salario Basico: $";
		cin >>salario_basico[i];

        cout <<"Realizo Horas Extras? (S/N): ";
        cin >>SN;
        if (SN == 'S' || SN == 's')
        {
            cout <<"Ingrese la cantidad (Tiempo): ";
            cin >>HExtraT[i];
			HExtraD[i] = HorasExtra(HExtraT[i]);
        }
		else
		{
           HExtraT[i] = 0;
		   HExtraD[i] = 0;
		}
        cout <<"Ha obtemido descuentos por prestamos? (S/N): ";
        cin >>SN;
        if (SN == 'S' || SN == 's')
        {
            cout <<"Ingrese el valor: $";
            cin >>DXPrestamo[i];
        }
        else
            DXPrestamo[i] = 0;

        cout <<"Ha realizado Ahorro Voluntario? (S/N): ";
        cin >>SN;
        if (SN == 'S' || SN == 's')
        {
            cout <<"Ingrese cantidad: $";
            cin >>Ahorro[i];
        }

        cout <<"Ingrese el Porcentaje por descuento de Seguridad Social:\n";
		cout <<"Ejemplo: 8.9 (sin signo - %): ";
        cin >>SegSocP[i];

		SalarioTotal[i] = salario_total(i);

        i++;
    }
}

/**
 * HorasExtra -  Calcula en Dinero horas extras
 * cant:        cantidad de horas realizadas
 * return:      Horas Extras en Dinero
*/
double HorasExtra(double cant)
{
	return HORAEXTRA * cant;
}

/**
 * salario_total - Calcula el salario a pagar despues de descuentos
 * idx:         index del empleado a calcular salario total
 * return:      Salario a pagar
 */
double salario_total(const unsigned int idx)
{
	int salario = (salario_basico[idx] + HExtraD[idx]);
	SegSocD[idx] = salario * (SegSocP[idx] / 100);

	return salario - SegSocD[idx] - DXPrestamo[idx] + Ahorro[idx];
}

/**
 * mostrar_datos_empleado - Imprime el registro total del empleado
 *                           con los calculos realizados
 * n_empleado:      cantidad de empleados
*/
void mostar_datos_empleados(const unsigned int n_empleados)
{
	unsigned int i = 0;

    while(i < n_empleados)
    {
        cout <<"\nEmpleado " <<i + 1 <<"\n";
        cout <<"Numero Cedula: " <<cedula[i] <<"\n";
        cout <<"Nombre Completo: " <<nombre[i] <<"\n";
        cout <<"Numero Telefonico: " <<telefono[i] <<"\n";
        cout <<"Cargo: "<<cargo[i] <<"\n";
		cout <<"Salario Basico: $" <<setprecision(10)
								  <<salario_basico[i] <<"\n";
		cout <<"Horas Extra en Tiempo:  " <<HExtraT[i] <<"\n";
		cout <<"Horas Extra en Dinero: $" <<setprecision(10)
										  <<HExtraD[i] <<"\n";
		cout <<"Descuento por Prestamo: $" <<setprecision(10)
										   <<DXPrestamo[i] <<"\n";
		cout <<"Dinero Ahorrado: $" <<Ahorro[i] <<"\n";
		cout <<"Descuento por Seguro Social: % " <<SegSocP[i] <<"\n";
		cout <<"Descuento por Seguro Social: $" <<setprecision(10)
												   <<SegSocD[i] <<"\n";
		cout <<"El Valor a Pagar es de $" <<setprecision(10)
										  <<SalarioTotal[i] <<" =\n";
        i++;
    }
}