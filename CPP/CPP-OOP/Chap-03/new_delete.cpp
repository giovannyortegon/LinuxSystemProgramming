#include<iostream>

using namespace std;

int main(void)
{
	int *y, *x;

	y = new int;

	*y = 17;
	cout <<y <<endl;
	cout <<"*y is: " <<*y <<endl;

	delete y;

	x = new int;


	cout <<x <<endl;
//	cout <<"*y is: " <<*y <<endl;

	return (0);
}
