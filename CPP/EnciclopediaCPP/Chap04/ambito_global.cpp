#include<iostream>

using namespace std;

float v;

int main()
{
	int v = 7;
	::v = 10.6; // Acceso a la variable local

	cout <<"Variable local: " <<v <<endl;
	cout <<"Variable Global: " <<::v <<endl;

	return (0);
}
