#include<iostream>

using namespace std;

int minimun(int arg1, int arg2);

int main()
{
	int x = 5, y = 89;

	cout <<minimun(x, y) <<endl;

	return (0);
}

int minimun(int a, int b)
{
	return (a < b) ? a : b;
}
