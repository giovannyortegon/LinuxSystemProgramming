#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

class Person {
    private:
        // data members
        char * firstName;
        char * lastName;
        char middleInitial;
        char * title;           // Mr., Ms., Mrs., Miss., Dr.,
    
    protected:
        void ModifyTitle(const char *);

    public:
        Person();
        Person(const char *, const char *, char, const char *);
        Person(const Person &);
        ~Person();

        // inline function definitions
        const char * GetFirstName() const { return firstName; }
        const char * GetLastName() const { return lastName; }
        const char * GetTitle() const { return title; }
        char GetMiddleInitial() const { return middleInitial; }
};

Person::Person() {
    firstName = lastName = 0;
    middleInitial = '\0';
    title = 0;
}

Person::Person(const char * fn, const char *ln, char mi, const char * t) {
    firstName = new char [strlen(fn) + 1];
    strncpy(firstName, fn, strlen(fn) + 1);
    lastName = new char [strlen(ln)+1];
    strncpy(lastName, ln, strlen(ln)+1);
    middleInitial = mi;
    title = new char [strlen(t) + 1];
    strncpy(title, t, strlen(t) + 1);
}

Person::Person(const Person &pers) {
    firstName = new char [strlen(pers.firstName) + 1];
    strncpy(firstName, pers.firstName, strlen(pers.firstName) + 1);
    lastName = new char [strlen(pers.lastName)+1];
    strncpy(lastName, pers.lastName, strlen(pers.lastName)+1);
    middleInitial = pers.middleInitial;
    title = new char [strlen(pers.title) + 1];
    strncpy(title, pers.title, strlen(pers.title) + 1);
}

Person::~Person() {
    delete firstName;
    delete lastName;
    delete title;
}

void Person::ModifyTitle(const char * newTitle) {
    delete title;
    title = new char [strlen(newTitle) + 1];
    strncpy(title, newTitle, strlen(newTitle)+1);
}

class Student: public Person {
    private:
        // data members
        float gpa;
        char * currentCourse;
        const char * studentId;

    public:
        // member function prototypes
        Student();
        Student(const char *, const char *, char, const char *,
                float, const char *, const char *);
        Student(const Student &);
        ~Student();

        void Print() const;
        void EarnPhD();

        // inline function definitions
        float GetGpa() const { return gpa; }
        const char * GetCurrentCourse() const { return currentCourse; }
        const char * GetStudent() const { return studentId; }
        // prototype only, see inline function definition below
        void SetCurrentCourse(const char *);
};

inline void Student::SetCurrentCourse(const char * c) {
    delete currentCourse;
    currentCourse = new char [strlen(c) + 1];
    strncpy(currentCourse, c, strlen(c)+1);
}

Student::Student():studentId(0) {           // default constructor
    gpa = 0.0;
    currentCourse = 0;
}

// alternate constructor
Student::Student(const char * fn, const char * ln, char mi,
                 const char * t, float avg, const char * course,
                 const char * id) : Person(fn, ln, mi, t) {
    gpa = avg;
    currentCourse = new char [strlen(course) + 1];
    strncpy(currentCourse, course, strlen(course)+1);
    char * temp = new char [strlen(id) + 1];
    strncpy(temp, id, strlen(id));
    studentId = temp;
}

// copy constructor
Student::Student(const Student &ps):Person(ps) {
    gpa = ps.gpa;
    currentCourse = new char [strlen(ps.currentCourse) + 1];
    strncpy(currentCourse, ps.currentCourse, strlen(ps.currentCourse)+1);
    char * temp = new char [strlen(ps.studentId)+1];
    strncpy(temp, ps.studentId, strlen(ps.studentId)+1);
    studentId = temp;
}

// destructor defination
Student::~Student() {
    delete currentCourse;
    delete (char *) studentId;
}

void Student::Print() const {
    // Private memeber of person are not  directly accessible
    cout <<GetTitle() <<" " <<GetFirstName() <<" ";
    cout <<GetMiddleInitial() <<". " <<GetLastName();
    cout <<" with id: " <<studentId <<" gpa: ";
    cout <<setprecision(2) <<gpa;
    cout <<" course: " <<currentCourse <<endl;
}

void Student::EarnPhD() {
    ModifyTitle("Dr.");
}

int main() {
    Student s1("Jo", "Li", 'U', "Ms.", 3.8, "C++", "178PSU");

    s1.Print();
    s1.SetCurrentCourse("Doctoral Thesis");
    s1.EarnPhD();
    s1.Print();

    return (0);
}