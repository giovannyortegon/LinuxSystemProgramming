#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
	int ref_zapato, talla, costo_zapato, precio_zapato;
	char sn, descripcion [20];
	
	printf("ADMINISTRAR VENTA DE ZAPATOS\n\n");
	printf("Digite la referencia del zapato\t\t");
	scanf("%d", &ref_zapato);
	fflush(stdin);
	printf("Digita descripcion del zapato\t\t");
	gets(descripcion);
	printf("Digita la talla\t\t\t\t");
	scanf("%d", &talla);
	printf("Digita el costo del zapato\t\t");
	scanf("%d", &costo_zapato);
	printf("Digita el precio de venta del zapato\t");
	scanf("%d", &precio_zapato);
	fflush(stdin);
	printf("La referecncia está disponible? (S/N)\t");
	sn = getchar();

	/* Empieza impresion de los datos */
	printf("\nLOS DATOS REGISTRADOS SON LOS SIGUIENTES\n");
	printf("\nReferencia zapato: %d", ref_zapato);
	printf("\nDescripcion del zapato: %s", descripcion);
	printf("\nTalla:\t %d", talla);
	printf("\nEsta disponible:\t %c", sn);
	printf("\nCosto zapato:\t %d", costo_zapato);
	printf("\nPrecio de venta del zapato:\t %d\n", precio_zapato);
	
	system ("pause");
	return EXIT_SUCCESS;	

}