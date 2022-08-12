#include<iostream>
#include<cstring>

using namespace std;

class Student {
    private:
        // data members
        char * firstName;
        char * lastName;
        char middleInitial;
        float gpa;
        char * currentCourse;
        const char * studentId;            // constant data member
        static int numStudents;         // static data memeber

    public:
        // member functio prototypes
        Student(); 
        Student(const char *, const char *, char, float, const char *, const char *);
        Student(const Student &);       // copy constructor
        ~Student();
        void Print() const;
        const char *GetFirstName() const { return firstName; }
        const char *GetLastName() const {return lastName; }
        char GetMiddleInitial() const { return middleInitial; }
        float GetGpa() const { return gpa; }
        const char * GetCurrent() const { return currentCourse; }
        void SetCurrentCuorse(const char *);        // only prototype
        static int GetNumberStudents();             // static memeber function

};

int Student::numStudents = 0;

inline int Student::GetNumberStudents() {
    return numStudents;
}

void Student::Print() const {
    cout <<firstName <<" " <<middleInitial <<" - ";
    cout <<lastName <<" with Id: " <<studentId;
    cout <<" and gpa: " <<gpa <<" is enrolled in: ";
    cout <<currentCourse <<endl;
}
inline void Student::SetCurrentCuorse(const char * course) {
    delete currentCourse;
    currentCourse = new char [strlen(course)+1];
    strncpy(currentCourse, course, strlen(course));
}

Student::Student(): studentId(0){ // memebber Initialize list
    firstName = lastName = 0;
    middleInitial = '\0';
    gpa = 0.0;
    currentCourse = 0;
    numStudents++;
}

Student::Student(const char * fn, const char *ln, char mi,
                 float avg, const char * course, const char * id) {
    firstName = new char [strlen(fn)+1];
    strncpy(firstName, fn, strlen(fn));

    lastName = new char [strlen(ln)+1];
    strncpy(lastName, ln, strlen(ln));

    middleInitial = mi;

    gpa = avg;

    currentCourse = new char [strlen(course)+1];
    strncpy(currentCourse, course, strlen(course));
    // SetCurrentCuorse(course);

    char * temp = new char [strlen(id)+1];
    strncpy(temp, id, strlen(id));
    studentId = temp;
    numStudents++;
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

    char * temp = new char [strlen(s.studentId)+1];
    strncpy(temp, s.studentId, strlen(s.studentId) +1);
    studentId = temp;
    numStudents++;
}
Student::~Student() {

    delete firstName;
    delete lastName;
    delete currentCourse;
    delete (char *) studentId;
    numStudents--;
}

int main() {
    Student s1("Nick", "Cole", 'S', 3.65, "C++", "112HAV");
    Student s2("Alex", "Tost", 'A', 3.78, "C++", "674HOP");

    cout <<s1.GetFirstName() <<" " <<s1.GetLastName();
    cout <<" Enrolled in " <<s1.GetCurrent() <<endl;

    cout <<s2.GetFirstName() <<" " <<s2.GetLastName();
    cout <<" Enrolled in " <<s2.GetCurrent() <<endl;

    // call a static member function in the preferred maner
    cout <<"There are " <<Student::GetNumberStudents();
    cout <<" students"  <<endl;

    // Though not preferable, we could also use:
    // cout << "There are " << s1.GetNumberStudents();
    // cout << " students" << endl;

    return (0);
} 