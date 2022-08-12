#include<iostream>

using namespace std;

//void fun(int y); // pass by value
void fun(int &y);


int main()
{
	int x = 10;

	fun(x);

	cout <<"Value of x in main: " <<x <<endl;

	return (0);
}
//void fun(int y)  // pass by value
void fun(int &y) 	// pass by reference
{
	y++;

	cout <<"Value of y in Fun: " <<y <<endl;

	return;
}
