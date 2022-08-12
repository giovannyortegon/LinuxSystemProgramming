#include<iostream>

using namespace std;

int global;

int main()
{
	static int sLocal;
	int aLocal;

	cout <<"Global = " <<global <<endl;
	cout <<"Static Local = " <<sLocal <<endl;
	cout <<"Local = " <<aLocal <<endl;

	return (0);
}
