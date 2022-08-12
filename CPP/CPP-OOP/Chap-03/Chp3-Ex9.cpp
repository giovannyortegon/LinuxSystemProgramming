#include<iostream>

using namespace std;

int main()
{
	void * unspecified;
	int * x;

	unspecified = new int;
	// void * must be cast to int * before it is dereferenced
	*((int *) unspecified) = 89;

	// let x point to the memory which unspecified points to
	x = (int *) unspecified;

	cout <<* x <<" " <<*((int *) unspecified) <<endl;

	return (0);
}
