#include<iostream>

using namespace std;

int main()
{
	int x = 5;
	const int &refInt = x;

	cout <<x <<" " <<refInt <<endl;

	// refInt = 6	// Ilegal -- refInt is const
	x = 7;			// we can inadvertenly change refInt
	cout <<x <<" " <<refInt <<endl;

	return (0);
}
