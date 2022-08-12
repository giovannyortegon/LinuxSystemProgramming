#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	int k = 0, elements = 0;
	vector <int> matrix(20, 0);
	vector <int>::iterator e;		// Iterator
// Fill a vector
	for (e = matrix.begin(); e != matrix.end(); e++)
		*e = k++ * 2;

	cout <<matrix.at(8) <<endl;		// get and print 7th element of vector
	cout <<matrix.size() <<endl;	// size of  vector

// Print elements of vector
	for (e = matrix.begin(); e != matrix.end(); e++)
	{
		k = *e;
		cout <<k <<" ";
	}
	cout <<endl;

//  get and print 1 st element of vector
	e = matrix.begin();
	k = *e;
	cout <<k <<endl <<endl;

// get and last element of vector
	e = matrix.end() - 1;
	k = *e;
	cout <<k <<endl <<endl;

	elements = matrix.size();
	cout <<elements <<endl;
	matrix.resize(elements - 5);
	elements = matrix.size();
	cout <<elements <<endl;

	cout <<matrix.empty();
	cout <<endl;

	matrix.pop_back();
	e = matrix.begin();
	matrix.erase(e + 3, e + 5);

//	matrix.clear();

	if (matrix.empty())
	{
		cout <<"exit"<<endl;
		return (0);
	}

	for (e = matrix.begin(); e != matrix.end(); e++)
	{
		k = *e;
		cout <<k <<" ";
	}
	cout <<endl;

	e = find (matrix.begin(), matrix.end(), 18);
	if (*e == 18)
	{
		matrix.erase(e);
		cout <<"element eliminado\n";
	}
	else
		cout <<"error: elemento no encontrado\n";

	matrix.push_back(17);
	matrix.insert(matrix.begin()+3, 2, -1);

	for (e = matrix.begin(); e != matrix.end(); e++)
	{
		k = *e;
		cout <<k <<" ";
	}
	cout <<endl;

	elements = matrix.size();
	cout <<elements <<endl;

	return (0);
}
