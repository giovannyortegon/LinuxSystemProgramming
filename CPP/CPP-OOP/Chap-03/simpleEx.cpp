#include<iostream>

using namespace std;

int main()
{
	int x = 10;
	int * pointerTox;

	pointerTox = &x;

	cout <<"x is " <<x <<" and *pointerTox is " <<*pointerTox <<endl;

	return (0);
}
