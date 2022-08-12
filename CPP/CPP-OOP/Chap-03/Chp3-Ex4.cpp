#include<iostream>

using namespace std;

int main()
{
	int numRows, numColumns;
	float ** TwoDimArray;

	cout <<"Enter number of rows: " <<flush;
	cin >>numRows;

	TwoDimArray = new float * [numRows];
	cout <<"Enter number of columns: ";
	cin >>numColumns;

	for (int i = 0; i < numRows; i++)
	{
		// allocate column quantity for each row
		TwoDimArray[i] = new float[numColumns];
		for (int j = 0; j < numColumns; j++)
		{
			TwoDimArray[i][j] = i + j + .05;
			cout <<TwoDimArray[i][j] <<" ";
		}
		cout <<endl;
	}

	for (int i = 0; i < numRows; i++)
		delete TwoDimArray[i];

	delete TwoDimArray;

	return (0);
}
