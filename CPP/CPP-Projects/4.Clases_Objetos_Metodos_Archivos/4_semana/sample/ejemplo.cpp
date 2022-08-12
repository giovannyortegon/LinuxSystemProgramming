#include<iostream>

using namespace std;

class Fraccion
{
	private:
		int Num;
		int Den;

	public:
		Fraccion();
		Fraccion(int, int);
		void Muestra();

	friend Fraccion operator + (Fraccion, Fraccion);	// Suma
	friend Fraccion operator - (Fraccion, Fraccion);	// Resta
	friend int operator > (Fraccion, Fraccion);			// comparacion por >
	friend double operator !(Fraccion f);	// Valor decimal de la fraccion
	friend double Valor(Fraccion f);		// Valor decimal de la fraccion
};

// construir que inicializa una fraccion con el valor de 1
Fraccion::Fraccion()
{
	Num = 1;
	Den = 1;
}

// Constructor que inicializa una fraccion con el valor dado por el usuario
Fraccion::Fraccion(int N, int D)
{
	Num = N;
	Den = D;
}

// Funcion que muestra la fraccion en la forma acostumbrada
void Fraccion::Muestra()
{
	cout <<Num <<'/' <<Den <<endl;
}
// Sobrecarga del operador + binario (suma de fracciones)
Fraccion operator + (Fraccion f1, Fraccion f2)
{
	Fraccion res;

	res.Num = (f1.Num * f2.Den + f2.Num * f1.Den);
	res.Den = f1.Den * f2.Den;

	return res;
}

// Sobrecarga del operador - binario (resta de fracciones)
Fraccion operator - (Fraccion f1, Fraccion f2)
{
	Fraccion res;

	res.Num = (f1.Num * f2.Den - f2.Den * f1.Den);
	res.Den = f1.Den * f2.Den;

	return res;
}
// Spbrecarga del operador ++ (sumar 1 unidad a la fraccion)
// Esta sobrecarga NO esta definida como friend y no es parte de la clase
Fraccion operator ++ (Fraccion f)
{
	Fraccion res, uno;

	res = f + uno;

	return res;
}

// Function friend que obtiene el valor decimal de la fraccion
double Valor(Fraccion f)
{
	return f.Num * 1.0 / f.Den;
}

// Sobrecarga del operador unitario ! para obtener
// el valor decimal de la fraccion
double operator !(Fraccion f)
{
	return f.Num * 1.0 /f.Den;
}

// Sobrecarga del operador > (mayor que) regresa verdadero o falso
int operator > (Fraccion A, Fraccion B)
{
	if (!A > !B)
		return 1;
	else
		return 0;
}
int main(void)
{
	int x, y;

	cout << "Teclea el valor de A(2, 5): ";
	cin >>x >>y;
	Fraccion A(x, y), B(3, 4), C;

	cout <<"A ";
	A.Muestra();

	cout <<"B ";
	B.Muestra();

	C = A + B;

	cout <<"Suma ";
	C.Muestra();

	C = A - B;
	cout <<"Resta ";
	C.Muestra();
	C = ++B;

	cout <<"Incremento ";
	C.Muestra();

	cout <<"Valor de la Fraccion ";
	cout <<Valor(A);
	cout <<"\nvalor de la fraccion ";
	cout <<!A;

	if (A > B)
		cout <<"\nA es mayor que B\n";
	else
		cout <<"\n A no es mayor que B\n";

	return (0);
}
