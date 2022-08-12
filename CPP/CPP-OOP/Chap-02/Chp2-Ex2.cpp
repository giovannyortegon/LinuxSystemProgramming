#include<iostream>

using namespace std;

int minimum(int, int);

int main()
{
	int x = 5, y = 89;

	cout <<minimum(x, y) <<endl;

	return (0);
}

int minimum(int a, int b)
{
	return (a < b) ? a : b;
}
