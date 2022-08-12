#include<iostream>

using namespace std;

int minimum(int arg1, int arg2 = 100000);

int main()
{
	int x = 5, y = 89;

	cout <<minimum(x) <<endl;
	cout <<minimum(x, y) <<endl;

	return (0);
}
int minimum(int a, int b)
{
	cout <<a <<endl;
	cout <<b <<endl;

	return (a < b) ? a : b;
}
