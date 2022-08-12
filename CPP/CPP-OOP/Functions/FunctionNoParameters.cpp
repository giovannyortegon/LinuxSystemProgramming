#include<iostream>

using namespace std;

int getData()
{
	int data;

	do
	{
		cout <<"Enter a positive integer: ";
		cin >> data;
	} while (data <= 0);

	return data;
}

int main()
{
	int number = getData();
	cout <<"Rigth-most digit: " <<number % 10 <<endl;

	return 0;
}
