#include<iostream>
#include<cstring>

using namespace std;

char suffix = 'A';

const char * genId(const char *);			// function prototype

int main()
{
	const char * newId1, * newId2;			// pointer declarations

	newId1 = genId("Group");				// function will allocate memory
	newId2 = genId("Group");

	cout <<"New ids: " <<newId1 <<" " <<newId2 <<endl;

	delete newId1;
	delete newId2;

	return (0);
}

const char * genId(const char * base)
{
	char * temp = new char[strlen(base) + 2];

	strcpy(temp, base);				// use base to initialize string
	temp[strlen(base)] =  suffix++;	// Append suffix to base
	temp[strlen(base) + 1] = '\0';	// Add null character

	return temp;
}
