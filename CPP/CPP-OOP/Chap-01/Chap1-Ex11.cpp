#include<iostream>

using namespace std;

namespace DataTypes
{
	int total;
	class LinkList
	{
		// Full class definition
	};
	class Stack
	{
		// Full class definition
	};
};

namespace AbstractDataTypes
{
	class Stack
	{
		// Full class definition
	};
	class Queue
	{
		// Full class definition
	};
};

// Add entries to the AbstractDataTypes namespace
namespace AbstractDataTypes
{
	int total;
	class Tree
	{
		// Full class definition
	};
};

int main(void)
{
	using namespace AbstractDataTypes;	// activate namespace
	using DataTypes::LinkList;			// activate only Link List

	LinkList list1;				// LinkList is found in DataTypes
	Stack stack1;				// Stack is found in AbstractDataTypes
	total = 5;					// total from active AbstractDataTypes

	DataTypes::total = 85;		// specify non-active memeber, total

	cout <<"total " <<total <<"\n";
	cout <<"DataTypes::total " <<DataTypes::total <<endl;

	return (0);
}
