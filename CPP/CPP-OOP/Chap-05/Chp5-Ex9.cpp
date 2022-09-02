#include<iostream>
#include<cstring>

using namespace std;

class Student {
    private:
        // data members
        char *firstName;
        char *lastName;
        char middleInitial;
        float gpa;
        char *currentCourse;
        const int studentId;            // constant data member

    public:
        // member functio prototypes
        Student(); 
        Student(const char *, const char *, char, float, const char *, int);
        Student(const Student &);       // copy constructor
        ~Student();
        const char *GetFirstName() { return firstName; }
        const char *GetLastName() {return lastName; }
        char GetMiddleInitial() { return middleInitial; }
        float GetGpa() { return gpa; }
        const char * GetCurrent() { return currentCourse; }
        void SetCurrentCuorse(const char *);        // only prototype
};

Student::Student(): studentId(0), gpa(0.0) { // memebber Initialize list
    firstName = lastName = 0;
    middleInitial = '\0';
    currentCourse = 0;
}

Student::Student(const char * fn, const char *ln, char mi,
                 float avg, const char * course, int id): studentId(id), gpa(avg), middleInitial(mi) {
    firstName = new char [strlen(fn)+1];
    strncpy(firstName, fn, strlen(fn));

    lastName = new char [strlen(ln)+1];
    strncpy(lastName, ln, strlen(ln));

    currentCourse = new char [strlen(course)+1];
    strncpy(currentCourse, course, strlen(course));
}

Student::Student(const Student &s):studentId(s.studentId) {
    firstName = new char [strlen( s.firstName )+1];
    strncpy(firstName, s.firstName, strlen(s.firstName));

    lastName = new char [strlen(s.lastName)+1];
    strncpy(lastName, s.lastName, strlen(s.lastName));

    middleInitial = s.middleInitial;
    gpa = s.gpa;

    currentCourse = new char [strlen(s.currentCourse)+1];
    strncpy(currentCourse, s.currentCourse, strlen(s.currentCourse));
}
Student::~Student() {

    delete firstName;
    delete lastName;
    delete currentCourse;

}

int main() {
    Student s1("Renee", "Alexander", 'Z', 3.7,  "C++", 1290);
    cout <<s1.GetFirstName() <<" " <<s1.GetLastName();
    cout <<" has gpa of: " << s1.GetGpa() <<endl;

    return (0);
}