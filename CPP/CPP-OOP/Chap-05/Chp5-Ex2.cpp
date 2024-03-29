#include<iostream>
#include<cstring>

using namespace std;

class Student
{
	public:
		char * firstName;		// data members
		char * lastName;
		char middleInitial;
		float gpa;
		char *currentCourse;		// member function prototypes

		void Initialize(const char *, const char *,
						char, float, const char *);
		void Print();
};

void Student::Initialize(const char *fn, const char * ln,
						 char mi, float gpa, const char * course)
{
	firstName = new char [strlen(fn) + 1];
	strncpy(firstName, fn, sizeof(firstName));
	lastName = new char [strlen(fn) + 1];
	strncpy(lastName, ln, sizeof(lastName));
	this->middleInitial = mi;				// optional use of 'this'
	this->gpa = gpa;						// required explicit use of 'this'
	currentCourse = new char [strlen(course) + 1];
	strncpy(currentCourse, course, sizeof(currentCourse));
}
// It is as if Student::Initialize() is written as:
// void
// Student_Initialize_constchar*_constchar*_float_constchar*
//			(Student *const this, const char *fn, const char *ln,
//			char mi, float avg, char *course)
// {
//		this->firstName = new char [strlen(fn) + 1];
//		strcpy(this->firstName, fn);
//		this->lastName = new char [strlen(ln) + 1];
//		strcpy(this->lastName, ln);
//		this->middleInitial = mi;
//		this->gpa = avg;
//		this->currentCourse = new char [strlen(course) + 1];
//		strcpy(this->currentCourse, course);
// }
// memeber funciton definition
void  Student::Print()
{
	cout <<firstName <<" ";
	cout <<middleInitial <<". ";
	cout <<lastName <<" has a gpa of:  ";
	cout <<gpa <<" and is enrolled in: ";
	cout <<currentCourse <<endl;
}
// It is as if Student::Print() is written as:
// void Student_Print(Student *const this)
// {
// cout << this->firstName << " ";
// cout << this->middleInitial << ". "
// cout << this->lastName << " has a gpa of: ";
// cout << this->gpa << " and is enrolled in: ";
// cout << this->currentCourse << endl;
// }
int main()
{
	Student s1;							// instance
	Student * s2 = new Student();			// ptr to an instance
	s1.Initialize("Mary", "Jacobs", 'I', 3.9, "C++");
	s2->Initialize("Sam", "Nelson", 'B', 3.2, "C++");
	s1.Print();
	s2->Print();

	// data members
	delete	s1.firstName; // delete dynamically allocated
	delete	s1.lastName;
	delete	s1.currentCourse;
	delete	s2->firstName;
	delete	s2->lastName;
	delete	s2->currentCourse;
	delete	s2;
	return 0;	// delete dynamically allocated instance
}
