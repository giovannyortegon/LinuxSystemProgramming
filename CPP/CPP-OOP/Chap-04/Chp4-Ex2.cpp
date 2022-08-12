#include<iostream>
#include<cstring>

using namespace std;

class Student
{
	public:
		char name[20];
		float gpa;
};

int main()
{
	Student s1;

	Student &sRef = s1;			// establish a reference to s1

	strcpy(s1.name, "Katje Katz");	// fill data
	s1.gpa = 3.75;

	cout <<s1.name <<" has GPA: " <<s1.gpa <<endl;
	cout <<sRef.name <<" has GPA: " <<sRef.gpa <<endl;

	strcpy(s1.name, "George Katz");	// fill data
	s1.gpa = 4.25;

	cout <<s1.name <<" has GPA: " <<s1.gpa <<endl;
	cout <<sRef.name <<" has GPA: " <<sRef.gpa <<endl;

	return (0);
}
