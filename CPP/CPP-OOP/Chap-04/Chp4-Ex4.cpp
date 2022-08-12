#include<iostream>

using namespace std;

int &CreateId();

int main()
{
	int &id1 = CreateId();
	int &id2 = CreateId();

	cout <<"ID 1: " <<id1 <<" ID 2: " <<id2 <<endl;

	delete &id1;
	delete &id2;

	return (0);
}

int &CreateId()
{
	static int count = 100;			// initialize with firts id
	int * memory = new int;

	* memory = count++;				// use count as id, then increment

	return (* memory);
}
