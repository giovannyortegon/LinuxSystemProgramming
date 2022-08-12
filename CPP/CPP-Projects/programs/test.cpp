#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a = 8, b = 15, c = 3, d = 4;
	float promedio;
	a = a /*+ b + c */;
	promedio = (a + b + c /* + d */) / 3;
	cout << "Primer número: " << a << endl;
	cout << "Segundo número: " << b << endl;
	cout << "Tercer número: " << c << endl;
	 cout << "Cuarto número: " << d << endl;
	cout << "El promedio es: " << promedio << endl;
}
