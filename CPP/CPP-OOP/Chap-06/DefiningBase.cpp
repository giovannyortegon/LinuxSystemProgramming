#include<iostream>

class Person {// base class
    private:
        char * name;
        char * title;

    public:
        Person();
        Person(char *, char *);
        Person(const Person &);
        ~Person();
        const char * GetTitle() const { return (title;) }
};

class Student: public Person { // derived
    private:
        float gpa;

    public:
        Student();
        Student(char *, char *, float);
        Student(const Student &);
        ~Student();
        float GetGpa() const { return (gpa); }
};




int main() {
    Person p1("Cyrus Bond", "Mr.");
    Student *s1 = new Student("Anne Lin", "Ms", 4.0);

    std::cout <<p1.GetTitle() <<" " <<s1->GetTitle();
    std::cout <<s1->GetGpa() <<std::endl;

    return (0);

}