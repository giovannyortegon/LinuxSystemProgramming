#include<iostream>

using namespace std;

void TryToAddOne(int );
void AddOne(int *);

int main()
{
	int x = 10, *y;

	y = new int;
	* y = 15;

	cout <<"x: " <<x <<" and *y: " <<*y <<endl;

	TryToAddOne(x);
	TryToAddOne(*y);
	cout <<"x: " <<x <<" and *y: " <<*y <<endl;

	AddOne(&x);
	AddOne(y);
	cout <<"x: " <<x <<" and *y: " <<*y <<endl;

	delete y;

	return (0);
}
void TryToAddOne(int arg)
{
	arg++;
}
void AddOne(int *arg)
{
	(*arg)++;
}
