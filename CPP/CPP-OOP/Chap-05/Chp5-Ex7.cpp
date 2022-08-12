#include<iostream>
#include<cstring>

using namespace std;

class University
{
	private:
		char * name;
		int numStudents;

	public:
		// constructor prototype
		University();						// Constructor
		University(const char *, int);		// Alternative constructor
		University(const University &);		// copy constructor
		~University();						// Destructor
		void Print();
};

University::University()
{
	name = 0;
	numStudents = 0;
}

University::University(const char * n, int num)
{
	name = new char [strlen(n) + 1];
	strncpy(name, n, sizeof(n));
	numStudents = num;
}

University::University(const University &u)
{
	name = new char [strlen(u.name) + 1];
	strncpy(name, u.name, sizeof(u.name));
	numStudents = u.numStudents;
}

University::~University()
{
	delete name;
	cout << "Destructor called " << this <<endl;
}

void University::Print()
{
	cout << "University: " << name;
	cout << " Enrollment: " << numStudents << endl;
}

int main()
{
	University u1("Temple Univesity", 39500);
	University *u2 = new University("Boston U", 32500);
	u1.Print();
	u2->Print();

	delete u2;

	return(0);
}
