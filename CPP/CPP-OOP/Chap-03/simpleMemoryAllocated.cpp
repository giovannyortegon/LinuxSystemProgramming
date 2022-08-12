#include<iostream>

using namespace std;

int main(void)
{
	int * y;

	y = new int;

	*y = 17;

	cout <<"*y is: " <<*y <<endl;
	cout <<"&y is: " <<&y <<endl;

	delete y;
	y = new int;
	cout <<"*y is: " <<*y <<endl;
	cout <<"&y is: " <<&y <<endl;

	return (0);
}
