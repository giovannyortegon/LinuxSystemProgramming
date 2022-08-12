#include<iostream>

using namespace std;

#define SIZE 100

class Pila
{
	public:
		Pila();			// constructor
		~Pila();		// Destructor
		void push(int i);
		int pop();
	private:
		int pila[SIZE];
		int tope;
};

// constructor de la clase pila
Pila::Pila()
{
	tope = 0;
	cout <<"Se inicializa la pila. " <<endl;
}
// destructor
Pila::~Pila()
{
	cout <<"se destruye la pila" <<endl;
}
void Pila::push(int valor)
{
	if (tope == SIZE)
	{
		cout <<"La Pila esta llena" <<endl;
		return;
	}
	pila[tope] = valor;
	tope++;
}
int Pila::pop()
{
	if (tope == 0)
	{
		cout <<"No hay nada en la pola" <<endl;
		return -1;
	}
	tope--;
	return pila[tope];
}
int main()
{
	Pila a, b;
	a.push(1);
	b.push(2);
	a.push(3);
	b.push(4);

	cout <<a.pop() <<endl;
	cout <<a.pop() <<endl;
	cout <<b.pop() <<endl;
	cout <<b.pop() <<endl;

	return (0);
}
