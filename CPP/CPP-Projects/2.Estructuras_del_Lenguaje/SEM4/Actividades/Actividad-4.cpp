/* Actividad 4 */
#include<iostream>
#include<string>

using namespace std;
/*
	main - adminitrar ventas de zapatos
 */
int main(void)
{
// Declaracion de variables
	char registrar, descripcion[30];
	string referencia;
    int talla, costo;

/*
 * Solicitando informacion al usuario 
 * hasta que decida terminarlo con s / n
*/
    cout <<"Desea registrar un Zapato s/n: ";
    cin >>registrar;
    
    while(registrar != 'n' )
    {
        cout <<"Digite la referencia: ";
	    cin >> referencia;
        cin.ignore(256, '\n');
	    cout <<"Digite una descripcion: ";
	    cin.getline(descripcion, 30);
        cout <<"Digite la Talla: ";
	    cin>> talla;
	    cout <<"Costo: ";
	    cin >> costo;
	    cout <<endl;
	    cout <<"Desea registrar OTRO Zapato s/n: ";
	    cin >>registrar;
    }
    
	cout <<endl <<"FIN DE LA APLICACION"<<endl;

// pausa en el programa
    system("pause");

// Finalizo el programa satisfactoriamente
	return EXIT_SUCCESS;

// Giovanny Ortegon
}
