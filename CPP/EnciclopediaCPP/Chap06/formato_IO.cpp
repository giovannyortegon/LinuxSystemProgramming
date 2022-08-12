#include<iostream>
#include<iomanip>

using namespace std;

int main(void)
{
	int v = 0;

	cout <<"Ingrese numero en base 8: \n";
	cin >>oct >> v;

	cout <<hex <<setw(10) <<v <<endl;
	cout <<dec <<setw(10) <<v <<endl;

	return (0);
}
