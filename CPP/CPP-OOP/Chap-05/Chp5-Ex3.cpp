#include<iostream>
#include<cstring>

using namespace std;

class Student
{
	private:
		char * firstName;
		char * lastName;
		char middleInitial;
		float gpa;
		char * currentCourse;
		char * studentId;

	public:
		void Initialize();
		void Initialize(const char *, const char *, char, float,
						const char *, const char *);
		void CleanUp();
		void Print();
};

void Student::Initialize()
{
	firstName = lastName = 0;
	middleInitial = '\0';
	gpa = 0.0;
	currentCourse = studentId = 0;
}
void Student::Initialize(const char * fn, const char *ln, char mi, float avg,
						 const char * course, const char * id)
{
	firstName = new char [strlen(fn) + 1];
	strncpy(firstName, fn, sizeof(fn));
	lastName = new char [strlen(ln) + 1];
	strncpy(lastName, ln, sizeof(ln));
	middleInitial = mi;
	gpa = avg;
	currentCourse = new char [strlen(course) + 1];
	strncpy(currentCourse, course, sizeof(course));
	studentId = new char [strlen(id) + 1];
	strncpy(studentId, id, sizeof(id));
}
void Student::CleanUp()
{
	delete firstName;
	delete lastName;
	delete currentCourse;
	delete studentId;
}

void Student::Print()
{
	cout <<firstName <<" " <<middleInitial <<". ";
	cout <<lastName <<" with id: " <<studentId;
	cout <<" has gpa: " <<gpa <<"  and enrrolled in: ";
	cout <<currentCourse <<endl;
}

int main()
{
	Student s1;

	s1.Initialize("Ming", "Li", 'I', 3.9, "C++", "178GW");
	s1.Print();
	// Error! firstName is private; not accessible in main()
	// cout <<s1.firstName <<endl;

	s1.CleanUp();

	return (0);
}
