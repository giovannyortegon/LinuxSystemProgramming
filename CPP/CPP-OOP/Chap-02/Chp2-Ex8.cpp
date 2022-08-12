#include<iostream>

using namespace std;

int maximum(int, int);
float maximum(float, float);

int main()
{
	char a = 'A', b = 'B';
	float x = 5.7, y = 9.89;
	int m = 6, n = 10;

	cout <<"The max is: " <<maximum(a, b) <<endl;
	cout <<"The max is: " <<maximum(x, y) <<endl;
	cout <<"The max is: " <<maximum(m, n) <<endl;

//	cout <<"The max is: " <<maximum(a, y) <<endl;
	cout <<"The max is: " <<maximum((float) a, y) <<endl;

	return (0);
}

int maximum(int arg1, int arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}
float maximum(float arg1, float arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}
