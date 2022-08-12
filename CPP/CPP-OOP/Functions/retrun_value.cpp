#include<iostream>

using namespace std;

bool isEven(int y);

int main()
{
	cout <<boolalpha <<isEven(5) <<endl;
	cout <<boolalpha <<isEven(10) <<endl;

	return (0);
}
bool isEven(int y)
{
	return ((y % 2) == 0);
}
