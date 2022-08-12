#include<iostream>

using namespace std;

void AddOne(int &);
void AddOne(int *);
void Display(int &);

int main()
{
	int x = 10, * y;

	y = new int;			// alocate y's memory
	*y = 15;				// derefence y to assign a value

	Display(x);
	Display(*y);

	AddOne(x);				// calls reference version (with an object)
	AddOne(*y);				// also calls reference version

	Display(x);				// Based on prototype, we see we are parsing
	Display(*y);			// by reference. Without prototype, we might
							// have guessed it was by value
	AddOne(&x);				// calls pointer version
	AddOne(y);				// also call pointer version

	Display(x);
	Display(*y);

	return (0);
}

void AddOne(int &arg)
{
	arg++;
}

void AddOne(int *arg)
{
	(*arg)++;
}

void Display(int &arg)
{
	cout <<arg <<" " <<flush;
}
