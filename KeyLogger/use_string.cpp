#include<iostream>

using namespace std;

string Welcome(string x);

int main()
{
	string x;

	cout <<"Enter your name: ";
	getline(cin, x);

	cout <<Welcome(x) <<endl;

	return (0);
}

string Welcome(string x)
{
	return "Your name is: " + x;
}
