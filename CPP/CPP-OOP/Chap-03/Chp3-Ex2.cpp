#include<iostream>

using namespace std;

struct collection
{
	int x;
	float y;
};

int main(void)
{
	int numElements;
	int *intArray;
	collection * collectionArray;

	cout <<"How many elements would you like? " <<flush;
	cin >>numElements;

	intArray = new int[numElements];
	collectionArray = new collection[numElements];

	// load each array with values
	for (int i = 0; i < numElements; i++)
	{
		intArray[i] = i;
		collectionArray[i].x = i;
		collectionArray[i].y = i + .5;

		cout <<intArray[i] <<"\n";
		// alternatively use ptr notation to print two values
		cout <<(*(collectionArray + i)).x <<" ";
		cout <<(*(collectionArray + i)).y <<endl;
	}

	delete intArray;
	delete [] collectionArray;

	return (0);
}
