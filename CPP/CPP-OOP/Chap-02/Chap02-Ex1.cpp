#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

// simple const variable declaration and initialization
const int MAX = 50;

int minimum(int a, int b)	// function definition with
{							// formal parameters
	return (a < b) ? a : b;	// conditional
}

int main(void)
{
	int x, y;

	cout <<"Enter two values: ";
	cin >> x >> y;

	const int MIN = minimum(x, y);		// const var initialized
										// with a function's retutn value
	cout << "Minimum is: " << MIN <<endl;

	char bigName[MAX];

	cout <<"Enter a name: ";
	cin >>setw(MAX) >> bigName;

	const int NAMELEN = strlen(bigName);	// another const
	cout <<"Length of name: " <<NAMELEN <<endl;

	return (0);
}
