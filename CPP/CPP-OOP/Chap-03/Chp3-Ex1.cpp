#include<iostream>

using namespace std;

struct collection
{
	int x;
	float y;
};

int main()
{
	collection * item;

	item = new collection;

	item->x = 9;

	(*item).y = 120.77;

	cout <<(*item).x <<" " <<item->y <<endl;

	delete item;

	return (0);
}
