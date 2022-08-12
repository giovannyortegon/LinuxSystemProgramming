#include<iostream>

using namespace std;

int main()
{
	int x = 10;
	int *p = new int;		// allocate memory for ptr variable

	*p = 20;				// dereference and assign value

	int &refInt1 = x;		// reference to an integer
	int &refInt2 = *p;		// also a reference to an integer

	cout <<x <<" " <<*p <<" ";
	cout <<refInt1 <<" " <<refInt2 <<endl;

	x++;					// update refInt1 and x
	(*p)++;					// update refInt2 and *p

	cout <<x <<" " <<*p <<" ";
	cout <<refInt1 <<" " <<refInt2 <<endl;

	refInt1++;				// update refInt1 and x
	refInt2++;				// update refInt2 and *p
	cout <<x <<" " <<*p <<" ";
	cout <<refInt1 <<" " <<refInt2 <<endl;

	return (0);
}
