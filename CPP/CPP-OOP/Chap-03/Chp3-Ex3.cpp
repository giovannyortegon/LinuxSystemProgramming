#include<iostream>

using namespace std;

const int NUNROWS = 5;

int main()
{
	float *TwoDimArray[NUNROWS];
	int numColumns;

	cout <<"Enter number of columns: ";
	cin >>numColumns;

	for (int i = 0; i < NUNROWS; i++)
	{
		// Allocate column quantity for each row
		TwoDimArray[i] = new float[numColumns];
		// load each column entry with data
		for (int j = 0; j < numColumns; j++)
		{
			TwoDimArray[i][j] = i + j + .05;
			cout <<TwoDimArray[i][j] <<" ";
		}
		cout <<endl;		// print newline between rows
	}

	for (int i = 0; i < NUNROWS; i++)
		delete TwoDimArray[i];

	return (0);
}
