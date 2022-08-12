#include<iostream>

using namespace std;

int minimum(int, int);

void function1(int x)
{
	int minimum(int arg1, int arg2 = 500);

	cout <<minimum(x) <<endl;
}
void funtcina2(int x)
{
	int minimum(int arg1, int arg2 = 90);

	cout <<minimum(x) <<endl;
}

int minimum(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	function1(30);
	funtcina2(450);

	return (0);
}
