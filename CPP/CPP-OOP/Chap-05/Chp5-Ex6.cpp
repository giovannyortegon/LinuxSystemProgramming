#include<iostream>
#include<cstring>

using namespace std;

class Student;

class Employee
{
	private:
		char firstName[20];
		char lastName[20];
		float salary;

	public:
		Employee();
		Employee(const char *, const char *, float);
		Employee(Student &);

		void Print();
};

class Student
{
	private:
		char * firstName;
		char * lastName;
		char middleInitial;
		float gpa;
		char * currentCourse;

	public:
		Student();
		Student(const char *, const char *, char, float, const char *);
		Student(const Student &);
		void Print();
		void CleanUp();
		float GetGpa();
		const char * GetFirstName();
		const char * GetLastName();
};

Employee::Employee()
{
	firstName[0] = lastName[0] = '\0';
	salary = 0.0;
}

// alternate constructor
Employee::Employee(const char * fn, const char * ln, float money)
{
	strncpy(firstName, fn, strlen(fn) + 1);
	strncpy(lastName, ln, strlen(ln) + 1);
	salary = money;
}

// conversion constructor - argument is a Student not Emplyee
Employee::Employee(Student &s)
{
	strncpy(firstName, s.GetFirstName(), sizeof(firstName + 1));
	strncpy(lastName, s.GetLastName(), sizeof(lastName + 1));
	if (s.GetGpa() >= 4.0)
		salary = 75000;
	else if (s.GetGpa() >= 3.0)
		salary = 60000;
	else
		salary = 50000;
}

void Employee::Print()
{
	cout << firstName << " " << lastName << " " << salary;
	cout << endl;
}
/*
 Definitions for Student's default, alternate, copy
 constructors, Print()and CleanUp() have been omitted
 for space, but are same as the prior Student example.
*/
float Student::GetGpa()
{
	return (gpa);
}
const char * Student::GetFirstName()
{
	return (firstName);
}

const char * Student::GetLastName()
{
	return (lastName);
}

Student::Student()
{
	firstName = lastName = 0;		// NULL pointer
	middleInitial = '\0';
	gpa = 0.0;
	currentCourse = 0;
}
// Alernate constructor member function definition
Student::Student(const char * fn, const char * ln, char mi,
				 float avg, const char * course)
{
	firstName = new char [strlen(fn) + 1];
	strncpy(firstName, fn, strlen(fn) + 1);
	lastName = new char [strlen(ln) + 1];
	strncpy(lastName, ln, strlen(ln) + 1);
	middleInitial = mi;
	gpa = avg;
	currentCourse = new char [strlen(course) + 1];
	strncpy(currentCourse, course, strlen(course) + 1);
}
// copy constructor definition = implement a deep copy
Student::Student(const Student &s)
{
	// allocate necessary memory for destionation string
	firstName = new char [strlen(s.firstName) + 1];
	// the copy source to destination string
	strncpy(firstName, s.firstName, strlen(s.firstName) + 1);
	lastName = new char [strlen(s.lastName) + 1];
	// data members which are not pointers do not need their
	// space allocated for deep copy, such as is done above
	strncpy(lastName, s.lastName, strlen(s.lastName) + 1);
	middleInitial = s.middleInitial;
	gpa = s.gpa;
	// allocate destination string space, then copy constents
	currentCourse = new char [strlen(s.currentCourse) + 1];
	strncpy(currentCourse, s.currentCourse, strlen(s.currentCourse) + 1);
}
// Member function definition
void Student::CleanUp()
{
	delete firstName;
	delete lastName;
	delete currentCourse;
}

// Member function definition
void Student::Print()
{
	cout << firstName << " " << middleInitial << ". ";
	cout << lastName << " has a gpa of: " << gpa;
	cout << " and id enrrolled in: " << currentCourse << endl;
}

int main()
{
	Student s1("Giselle", "LeBrun", 'A', 3.5, "C++");
	Employee e1(s1);
	e1.Print();
	s1.CleanUp();

	return (0);
}
