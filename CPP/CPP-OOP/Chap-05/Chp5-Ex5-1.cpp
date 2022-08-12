#include<iostream>
#include<cstring>

using namespace std;

class Student
{
	private:
		// data members
		string firstName;
		string lastName;
		char middleInitial;
		float gpa;
		char * currentCourse;

	public:
		// member function prototype
		Student();						// default constructor
		Student(const char *, const char *, char, float, const char *);
		Student(const Student &) = delete;		// copy constructor prototype
		void setFirstName(const string &);
		void CleanUp();
		void Print();
};

Student::Student()
{
	middleInitial = '\0';
	gpa = 0.0;
	currentCourse = 0;
}

// Alernate constructor member function definition
Student::Student(const char * fn, const char * ln, char mi,
				 float avg, const char * course)
{
	firstName = fn;
	lastName = ln;
	middleInitial = mi;
	gpa = avg;
	currentCourse = new char [strlen(course) + 1];
	strncpy(currentCourse, course, strlen(course) + 1);
}
void Student::setFirstName(const string & fn)
{
//	firstName = new char[strlen(fn) + 1];
	firstName = fn;
}
/*
// copy constructor definition = implement a deep copy
Student::Student(const Student &s)
{
	firstName = s.firstName;
	lastName = s.lastName;
	middleInitial = s.middleInitial;
	gpa = s.gpa;
	// allocate destination string space, then copy constents
	currentCourse = new char [strlen(s.currentCourse) + 1];
	strncpy(currentCourse, s.currentCourse, strlen(s.currentCourse) + 1);
}*/
// Member function definition
void Student::CleanUp()
{
	delete currentCourse;
}

// Member function definition

void Student::Print()
{
	cout << firstName << " " << middleInitial << ". ";
	cout << lastName << " has a gpa of: " << gpa;
	cout << " and id enrrolled in: " << currentCourse << endl;
}

int main(void)
{
	// instantiate two Student
	Student s1("Zachary", "Moon", 'R', 3.7, "C++");
	Student s2("Gabrielle", "Doone", 'A', 3.7, "C++");

	// These initialization implicitly invoke copy constructor
//	Student s3(s1);
//	Student s4 = s2;

//	s3.setFirstName("Zack");
//	s4.setFirstName("Gabby");

	// This sequence does not invoke copy constructor
	// This is instead an assignment.
	// Student s5("Giselle", "LeBrun", 'A', 3.1, "C++);
	// Student s6;
	// s6 = s5; // this is an assignment, not initialization

	s1.Print();
//	s3.Print();
	s2.Print();
//	s4.Print();

	s1.CleanUp();
	s2.CleanUp();
//	s3.CleanUp();
//	s4.CleanUp();

	return (0);
}
