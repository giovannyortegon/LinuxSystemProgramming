#include<iostream>
#include<cstring>

using namespace std;

struct student
{
	char name[20];
	float semesterGrades[5];
	float gpa;
};

int main(void)
{
	student s1;

	strcpy(s1.name, "George Katz";
	s1.semesterGrades[0] = 3.0;
	s1.semesterGrades[1] = 4.0;
	s1.gpa = 3.5;

	cout <<s1.name <<" has GPA: " <<s1.gpa <<endl;

	return ();

