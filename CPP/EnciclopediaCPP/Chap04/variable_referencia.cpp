#include<iostream>

using namespace std;

int main()
{
	int conta = 0;
	int &cont = conta;

	cont++;

	cout <<conta <<endl;
	cout <<cont <<endl;

	return (0);
}
