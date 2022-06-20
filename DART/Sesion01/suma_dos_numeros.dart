int main() {
	var number_1 = 2;
	var number_2 = 3;

	var resultado = suma_numero(number_1, number_2);

	print("Resultado suma: " + resultado.toString());

	return (0);
}

int suma_numero(int number_1, int number_2) {
	return number_1 + number_2;
}
