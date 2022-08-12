#include<iostream>

using namespace std;

int main()
{
	int dim1, dim2, dim3;
	int ***ThreeDimArray;

	cout <<"Enter dim 1, dim 2, dim 3: ";
	cin >> dim1 >> dim2 >> dim3;

	ThreeDimArray = new int ** [dim1];			// allocate dim 1

	for (int i = 0; i < dim1; i++)
	{
		// allocate dim2
		ThreeDimArray[i] = new int * [dim2];

		for (int j = 0; j < dim2; j++)
		{
			// allocate dim3
			ThreeDimArray[i][j] = new int[dim3];
			for (int k = 0; k < dim3; k++)
			{
				ThreeDimArray[i][j][k] = i + j + k;
				cout <<ThreeDimArray[i][j][k] <<" ";
			}
			cout <<endl;
		}
		cout <<endl;
	}

	for (int i = 0; i < dim1; i++)
	{
		for (int j = 0; j < dim2; j++)
			delete ThreeDimArray[i][j];
		delete ThreeDimArray[i];
	}
	delete ThreeDimArray;

	return (0);
}
