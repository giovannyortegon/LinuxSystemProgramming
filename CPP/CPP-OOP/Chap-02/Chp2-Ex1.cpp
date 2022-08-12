#include<iostream>
#include<iomanip>
#include<cstring>


using namespace std;

const int MAX = 50;

int minimum(int a, int b)
{
	return (a < b)? a : b;
}

int main()
{
	int x, y;

	cout <<"Enter two values: ";
	cin >>x >>y;

	const int MIN = minimum(x, y);

	cout <<"Minimum is: " <<MIN <<endl;

	char bigName[MAX];
	cout <<"Enter a name: ";
	cin >> setw(MAX) >> bigName;

	const int NAMELEN = strlen(bigName);
	cout <<"Length of name: " <<NAMELEN <<endl;

	return (0)
}
