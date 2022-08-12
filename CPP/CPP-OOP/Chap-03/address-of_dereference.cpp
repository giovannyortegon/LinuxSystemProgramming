#include<iostream>

using namespace std;

int main(void)
{
	int x = 10;
	int * pointerToX;		// pointe to an integer

	pointerToX = &x;
	cout <<"x is " <<x <<" and * pointerToX is " <<*pointerToX;

	return (0);
}
