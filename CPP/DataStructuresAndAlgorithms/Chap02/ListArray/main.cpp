#include <iostream>
#include "list.h"

using namespace std;

int main() {
	List list = List();

	cout <<list.Count() <<endl;
	// Add nodes
	list.Insert(0, 32);
	list.Insert(1, 12);
	list.Insert(2, 87);
	list.Insert(3, 35);
	list.Insert(4, 92);

	cout <<list.Count() <<endl;
	cout <<endl;
	
	for (int i = 0; i < list.Count(); i++) {
		cout << list.Get(i) <<endl;
	}
	cout <<endl;

	list.Insert(2, 25);
	list.Insert(2, 71);
	cout <<list.Count() <<endl;
	cout <<endl;

	cout <<"New list again" <<endl;

	for (int i = 0; i < list.Count(); i++) {
		cout << list.Get(i) <<endl;
	}

	cout <<"Search 71" <<endl;
	int result = list.Search(71);
	cout << result <<endl;

	cout <<"Remove 71" <<endl;
	list.Remove(result);


	cout <<"New list again" <<endl;
	for (int i = 0; i < list.Count(); i++) {
		cout << list.Get(i) <<endl;
	}

	cout <<list.Search(35);
	cout <<endl;

	return (0);
}
