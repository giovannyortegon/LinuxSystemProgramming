#include<iostream>
#include<cstring>

using namespace std;

class Student
{
	private:
		// data members
		char * firstName;
		char * lastName;
		char middleInitial;
		float gpa;
		char * currentCourse;

	public:
		// member function prototypes
		Student();
		Student(const char *, const char *, char, float, const char *);
		Student(const Student &);
		~Student();
		void Print();

		// inline function definitions
		const char * GetFirstName() { return firstName; }
		const char * GetLastName() { return lastName; }
		char GetMiddleInitial() { return middleInitial; }
		float GetGpa() { return gpa; }
		const char * GetCurrentCourse() { return currentCourse; }
		// prototype only, see inline function definition below
		void SetCurrentCourse(const char *);
};

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


inline void Student::SetCurrentCourse(const char * c)
{
	delete currentCourse;
	currentCourse = new char [strlen(c) + 1];
	strncpy(currentCourse, c, sizeof(c) + 1);
}

void Student::Print()
{
	cout << firstName << " " << middleInitial << ". ";
	cout << lastName << " has a gpa of: " << gpa;
	cout << " and id enrrolled in: " << currentCourse << endl;
}
Student::~Student()
{
	delete firstName;
	delete lastName;
	delete currentCourse;
}

int main(int argc, char * argv[])
{
	Student s1("Jo", "Muritz", 'Z', 4.0, "C++");
	cout << s1.GetFirstName() <<" " << s1.GetLastName();
	cout << " Enrolled in: " << s1.GetCurrentCourse() << endl;

	s1.SetCurrentCourse("Advanced C++ Programming.");

	cout << s1.GetFirstName() << " " << s1.GetLastName();
	cout << " New course: " << s1.GetCurrentCourse() << endl;

	return (0);
}
