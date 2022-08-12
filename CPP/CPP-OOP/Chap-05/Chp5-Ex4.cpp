#include<iostream>
#include<cstring>

using namespace std;

class University
{
	private:
		char name[30];
		int numStudents;
	public:
		// contructor prototypes
		University();
		University(const char *, int);
		void Print();
};

University::University()
{
	name[0] = '\0';
	numStudents = 0;
}
University::University(const char * n, int num)
{
	strncpy(name, n, sizeof(name));
	numStudents = num;
}

void University::Print()
{
	cout <<"University: " <<name;
	cout <<" Enrollment: " <<numStudents <<endl;
}

int main()
{
	University u1;
	University u2("University of Delaware", 23800);
	u1.Print();
	u2.Print();

	return (0);
}
