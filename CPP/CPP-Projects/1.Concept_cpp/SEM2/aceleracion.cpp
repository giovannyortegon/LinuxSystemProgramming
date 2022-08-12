#include<iostream> // header, entrada/salida estander
#include<stdlib.h> // header, para usar EXIT_SUCCESS

using namespace std; // Uso salida estandar

int main()
{
    /*
        ac = aceleracion
        V_in = Velocidad Inicial
        V_fn = Velocidad Final
        T_in = Tiempo inicial
        T_fn = Tiempo Final
        dV = diferencia de Velocidad
        dT = diferencia de Tiempo
    */
    float ac, V_in, V_fn, T_in, T_fn, dV, dT;

    cout<<"**** Hallar la Aceleracion ****"<<endl;
    // Muestra titulo del programa
    cout<<"Ingrese la velocidad inicial:"<<endl;
    // Solicita velocidad inicial
    cin>>V_in;
    // Ingresa a memoria el valor de velocidad inicial
    cout<<"Ingrese la velocidad final:"<<endl;
    // Solicita valocidad final
    cin>>V_fn;
    // Ingresa a memoria el valor de velocidad final
    cout<<"Ingrese la Tiempo inicial:"<<endl;
    // Solicita Tiempo inicial
    cin>>T_in;
    // Ingresa a memoria el valor de tiempo inicial
    cout<<"Ingrese la Tiempo final:"<<endl;
    // Solicita tiempo final
    cin>>T_fn;
    // Ingresa a memoria el valor de tiempo final

    // Formula para hallar la aceleracion.
    ac = (V_fn - V_in) / (T_fn - T_in);
    // Muestra el resultado de resolver la formula
    cout<<endl<<"La aceleracion: "<<ac<<endl;
    // Genera una pausa en el sistema
    system("pause");
    // Finalizacion del programa son errores
    return EXIT_SUCCESS;
}