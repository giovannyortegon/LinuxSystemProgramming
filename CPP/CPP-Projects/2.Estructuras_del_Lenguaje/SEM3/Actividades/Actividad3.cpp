/*
 * Actividad 333: Estudio de caso venta de zapatos de Sofía
*/
#include<iostream>
//#include<string>

using namespace std;
/*
	main - Adminitra ventas de zapatos
 */
int main(void)
{
// Declaracion de variables con respecto a los zapatos
	char disponibilidad, descripcion[30], utilidad;
	string referencia;
    int talla, costoUnidad, costoTotal, precioUnidad, precioTotal;
    int cantidad, utilidadUnidad, utilidadTotal, utilidadBruta;
    int porcentajeUtilidad;
// Solicitando informacion al usuario
	cout <<"ADMINISTRAR VENTAS DE ZAPATOS"<<endl;
	cout <<"Digite la referencia del zapato... "<<endl<<endl;
	cin >> referencia;
	cin.ignore(256, '\n');
	cout <<endl << "Digite una descripcion del zapato..."<<endl<<endl;
	cin.getline(descripcion, 30);
	cout <<endl <<"Digite la talla..."<<endl<<endl;
	cin >> talla;
	cout <<endl;
    cout <<"Digite la letra si esta disponible o no para la venta S/N...";
    cout <<endl<<endl;
	cin >> disponibilidad;
	cout <<endl <<"Digite la cantidad de Zapatos que existen de esta referencia... " <<endl <<endl;
	cin >> cantidad;
    cout <<endl <<"Digite el costo del zapato..."<<endl<<endl;
	cin >> costoUnidad;
/*
 *  De acuedo al costo del zapato se asigna un porcentaje de utlidad
 *  y un tipo para calcular el precio del zapato
 */
	if (costoUnidad <= 30000)
	{ 
		utilidad = 'A';
	} else if ((costoUnidad > 30000) && (costoUnidad <= 60000))
	{
		utilidad = 'B';

	} else if(costoUnidad > 60000)
	{
		utilidad = 'C';
	}

	switch(utilidad)
	{
		case 'A':
			porcentajeUtilidad = 50;
			break;
		case 'B':
			porcentajeUtilidad = 40;
			break;
		case 'C':
			porcentajeUtilidad = 30;
			break;
	}
/* Realiza calculos:
   - Costo Total del producto de acuerdo a la cantidad
   - precio por unidad de acuerdo con el costo
   - Precio final del producto de acuerdo a la cantidad
   - Utilidad por unidad porcenaje por unidad
   - Utilidad por la cantidad de productos vendidos
*/
	costoTotal = costoUnidad * cantidad;
	utilidadUnidad = (costoUnidad * porcentajeUtilidad) / 100;
	precioUnidad = costoUnidad + utilidadUnidad;
	precioTotal =  precioUnidad * cantidad;
	utilidadTotal = utilidadUnidad * cantidad;
// Limpia pantalla	
 	system("cls");
// Imprimiendo Resultados de la informacion suministrada
    cout <<"LOS DATOS REGISTRADOS SON LOS SIGUIENTES"<<endl;
	cout <<endl <<"REFERENCIA: " <<referencia <<endl;
	cout <<"TIPO: " <<utilidad <<endl;
	cout <<"DESCRIPCION: " <<descripcion <<endl;
	cout <<"TALLA: " <<talla <<endl;
	cout <<"DISPONIBILIDAD: "<<disponibilidad <<endl;
	cout <<"CANTIDAD DE ZAPATOS: " <<cantidad <<endl;
    cout <<"COSTO UNIDAD: " <<costoUnidad <<endl;
    cout <<"COSTO TOTAL: " <<costoTotal <<endl;
    cout <<"PRECIO UNIDAD: " <<precioUnidad <<endl;
	cout <<"PRECIO TOTAL DE " <<cantidad <<" UNIDADES: "<<precioTotal <<endl;
	cout <<"UTILIDAD POR UNIDAD: " <<utilidadUnidad <<endl;
	cout <<"UTILIDAD TOTAL: " <<utilidadTotal <<endl;
	cout <<"PORCENTAJE DE UTILIDAD: " <<porcentajeUtilidad <<endl;
// Mensaje de Salida    
    cout <<endl<<"Gracias por digitar la informacion" <<endl;
// realiza una pausa en el sistema 
	system("pause");
// Finalizo el programa satisfactoriamente
	return EXIT_SUCCESS;
// GIOVANNY ORTEGON
}
