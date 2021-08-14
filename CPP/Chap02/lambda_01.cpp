#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v {1, 2, 3, 4, 5, 6};

	for_each (begin(v), end(v), [](int x) {cout <<x <<endl;});

	return (0);
}
