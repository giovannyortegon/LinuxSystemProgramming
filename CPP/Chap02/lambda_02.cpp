#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v {1, 2, 3, 4, 5, 6};
	string prefix ("0");

	for_each(begin(v),end(v), [&prefix](int x) { cout <<prefix <<x <<endl;} );

	return (0);
}
