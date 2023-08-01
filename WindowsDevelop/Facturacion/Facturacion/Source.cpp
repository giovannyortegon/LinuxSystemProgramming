#include<iostream>
#include<cstring>

#define N 3

void funtion(int idx, std::string &prod, int &prec);
void mostrar(std::string, int);

int main() {
	int c = 1;
	std::string producto;
	int precio;
	int precio_total;

	std::string l_productos[N];
	int * cant_product = new int[N];
	int * t_product = new int[N];
	int cantidad;

	while (c != 4) {
		c = 0;
		std::cout << "***** Menu *****" << std::endl;
		std::cout << "1. Mostrar Productos" << std::endl;
		std::cout << "2. Agregar Productos" << std::endl;
		std::cout << "3. Mostrar Precio Total Productos" << std::endl;
		std::cout << "4. Salir" << std::endl;
		std::cout << "> ";
		std::cin >> c;

		if (c == 4)
			break;

		switch (c)
		{
		case 1:
			mostrar(producto, precio);
			break;
		case 2:
			c = 1;
			while (c != 0) {
				mostrar(producto, precio);
				std::cout << "0. Para salir" << std::endl;
				std::cout << "Introduzca numero producto: ";
				std::cin >> c;
				if (c == 0)
					break;

				std::cout << "cantidad: ";
				std::cin >> cantidad;

				funtion(c - 1, producto, precio);

				std::cout << "Agregando: " << producto << std::endl;
				l_productos[c - 1] = producto;
				cant_product[c - 1] += cantidad;
				t_product[c - 1] += precio * cantidad;
			}
			break;
		case 3:
			if (l_productos->length() == 0) {
				std::cout << "Lista Vacia" << std::endl;
				break;
			}
			else {
				for (int i = 0; i < N; i++) {
					std::cout << cant_product[i] << " ";
					std::cout << l_productos[i] << " ";
					std::cout << t_product[i] / cant_product[i] << " " << t_product[i] << std::endl;
				}
				for (int i = 0; i < N; i++)
					precio_total += t_product[i];
				std::cout << "Total: " << precio_total << std::endl;
			}
			break;
		default:
			std::cout << "[!] Opcion no valida!!" << std::endl;
			break;
		}

	}

	delete[] cant_product;
	delete[] t_product;
	return (0);
}

void funtion(int idx, std::string &prod, int &prec) {

	std::string productos[N]{ "Leche", "Pan", "Huevos" };
	int prod_len = sizeof(productos) / sizeof(std::string);
	int precios[N]{ 5000, 500, 500 };

	prod = productos[idx];
	prec = precios[idx];

	// std::cout <<productos[idx] <<precios[idx];
}

void mostrar(std::string producto, int precio) {

	std::cout << std::endl << "***** PRODUCTOS *****" << std::endl;
	for (int i = 0; i < N; i++) {
		funtion(i, producto, precio);
		std::cout << i + 1 << ". " << producto << " " << precio << std::endl;
	}
}
