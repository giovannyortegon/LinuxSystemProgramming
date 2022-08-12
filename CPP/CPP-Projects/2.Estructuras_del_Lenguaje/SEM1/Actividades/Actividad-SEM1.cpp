#include<iostream>
#include<string>

using namespace std;
/*
	main - adminitrar ventas de zapatos
 */
int main(void)
{
	// Declaracion de variables con respecto a los zapatos
	char disponibilidad, descripcion[30];
	string referencia;
    int talla, costo, precio;

	cout <<"ADMINISTRACION DE VENTAS DE ZAPATOS"<<endl;
	cout <<"Digite la referencia del zapato... "<<endl<<endl;
	cin >> referencia;
	cin.ignore(256, '\n');
	cout <<endl << "Digite una descripcion del zapato..."<<endl<<endl;
	cin.getline(descripcion, 30);
	cout <<endl <<"Digite la talla..."<<endl<<endl;
	cin>> talla;
	cout <<endl << "Digite la letra si esta disponible o no para la venta S/N..."<<endl<<endl;
	cin >> disponibilidad;
	cout <<endl <<"Digite el costo del zapato..."<<endl<<endl;
	cin >> costo;
	cout <<endl <<"Digite el precio de venta de zapato..."<<endl<<endl;
	cin >>precio;
	
	system("cls");
    cout <<"LOS DATOS REGISTRADOS SON LOS SIGUIENTES"<<endl;
	cout <<"REFERENCIA: " <<referencia <<endl;
	cout <<"DESCRIPCION: " <<descripcion <<endl;
	cout <<"TALLA: " <<talla <<endl;
	cout <<"DISPONIBILIDAD: "<<disponibilidad<<endl;
	cout <<"COSTO: " <<costo<<endl;
	cout <<"PRECIO: " <<precio <<endl;
	cout <<endl<<"Gracias por digitar la informacion"<<endl;
 
    system("pause");

	return EXIT_SUCCESS;
}
