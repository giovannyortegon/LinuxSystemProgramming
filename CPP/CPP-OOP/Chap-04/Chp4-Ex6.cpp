#include<iostream>

using namespace std;

class Collection
{
	public:
		int x;
		float y;
};

void Update(Collection &);			// function prototypes
void Print(const Collection &);

int main()
{
	Collection collect1, * collect2;

	collect2 = new Collection;		// allocate memory from heap

	Update(collect1);				// a ref to the object will be passed
	Update(*collect2);				// same here -- * collect2 is an object
	Print(collect1);
	Print(*collect2);

	delete collect2;				// delete heap memory

	return (0);
}

void Update(Collection &c)
{
	cout <<"Enter x and y members: ";
	cin >>c.x >>c.y;
}

void Print(const Collection &c)
{
	cout <<"X member: " <<c.x;
	cout <<"  y member: " <<c.y <<endl;
}
