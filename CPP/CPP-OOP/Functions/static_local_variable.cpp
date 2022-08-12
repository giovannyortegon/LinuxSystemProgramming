#include <iostream>

using namespace std;

void func();

int main()
{
	func();
	func();
	func();

	return (0);
}
void func()
{
	static int count = 0;

	count++;

	cout <<"count = " <<count <<endl;
}
