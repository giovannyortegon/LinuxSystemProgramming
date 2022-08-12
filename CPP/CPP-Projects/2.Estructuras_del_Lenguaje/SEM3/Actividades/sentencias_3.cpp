#include <iostream>

using namespace std;

int main()
{
    int dia;
    string nombre_dia;

    cout <<"Digite un dia de semane para determinar su nombre: " <<endl <<endl;
    cin >>dia;

    switch (dia)
    {
    case 1:
        nombre_dia = "Domingo";
        break;
    case 2:
        nombre_dia = "Lunes";
        break;
    case 3:
        nombre_dia = "Martes";
        break;
    case 4:
        nombre_dia = "Miercoles";
        break;
    case 5:
        nombre_dia = "Jueves";
        break;
    case 6:
        nombre_dia = "Viernes";
        break;
    case 7:
        nombre_dia = "Sabado";
        break;
    default:
        nombre_dia = "";
        break;
    }

    if (nombre_dia != "")
    {
        cout <<"El dia es: " <<nombre_dia <<endl <<endl;
    }else {
        cout <<"El numero digitado no corresponde a dias de la semana." <<endl <<endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}