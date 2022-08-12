#include<iostream> // header, entrada/salida estandar
#include<stdlib.h> // header, para usar EXIT_SUCCESS

using namespace std; // permite usar la salidar estandar
// Fincion Principal 
int main()
{
    // Declaracion de variables
    int multiplicando, multiplicador, producto, numero;

    cout<<"Ingrese el numero a multiplicar:"<<endl; // Solicutar al ususario el multiplicando
    cin>>multiplicando; // Ingresando en memoria el multiplicando 

    cout<<"Ingrese hsta que numero sea multiplicado:"<<endl; // Solicitando al usuarui el multiplicador
    cin>>numero; // ingresando en memoria 'numero' el valor hasta que nuemro se va a multiplicar 
    cout<<"------------------------"<<endl; // Separador en formato de lineas "-----"

    for (multiplicador = 1; multiplicador <= numero; multiplicador++) // Instruccion for
    {
        /*
            Realiza la multiplicacion del numero ingresado por el usuario
            las veces que el mismo usuario lo indique a partir del numero 1,
            de la misma manera, imprimira el producto de la multiplicaion a mediada
            que la iteracion aumenta de uno en uno mientras el "multiplicador"
            sea menor o igual "numero".
            
            Formato:
        
            "5 x 1 = 5"
            "5 x 2 = 10" ...
        */
        producto = multiplicando * multiplicador; // Relica la multiplicacion
        cout<<multiplicando <<" x "<<multiplicador<<" = "<<producto<<endl;
        // Visualiza el producto con el formato mostrado en el anterior comentario.
    }

    system("pause"); // Pausa el sistema hasta que presione una tecla
    return EXIT_SUCCESS; // Ejecusion sin errores;
}
