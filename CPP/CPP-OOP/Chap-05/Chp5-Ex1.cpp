#include<iostream>
#include<cstring>

using namespace std;

struct student
{
	char name[20];
	float gpa;

	void Initialize(const char *, float); //fn.prototype
	void Print();
};

class University
{
	public:
		char name[30];
		int numStudents;
		void Initialize(const char *, int);
		void Print();
};

void student:: Initialize(const char * n, float avg)
{
	strncpy(name, n, sizeof(name));
	gpa = avg;
}

void student::Print()
{
	cout <<name <<" GPA: " <<gpa <<endl;
}

void University::Initialize(const char *n, int num)
{
	strncpy(name, n, sizeof(name));
	numStudents = num;
}

void University::Print()
{
	cout <<name <<" Enrollment: " <<numStudents <<endl;
}

int main()
{
	student s1;					// instantiate a student (struct)
	s1.Initialize("Gabby Doone", 4.0);
	s1.Print();

	University u1;				// instantiate a University (class)
	u1.Initialize("GWU", 25600);
	u1.Print();

	University * u2;			// pointer declaration
	u2 = new University();
	u2->Initialize("UMD", 40500);
	u2->Print();
	delete u2;

	return (0);
}
