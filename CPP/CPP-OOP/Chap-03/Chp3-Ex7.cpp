#include<iostream>
#include<iomanip>

using namespace std;

const int MAX = 20;
char * createName();

int main()
{
	char * name;

	name = createName();
	cout <<"Name: " <<name <<endl;

	delete name;

	return (0);
}
char *createName()
{
	char *temp = new char[MAX];

	cout <<"Enter name: " <<flush;
	cin >>setw(MAX) >>temp;

	return temp;
}
