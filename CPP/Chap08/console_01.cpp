#include<iostream>
#include<string.h>

int main() {
    std::string name;
    std::cout <<"Name: ";
    std::cin >>name;
    std::string surname;
    std::cout <<"surname: ";
    std::cin >> surname;

    int age;
    std::cout <<"Age: ";
    std::cin >> age;
    std::cout <<"Hello, " <<name <<", " <<surname <<": " <<age <<std::endl;

    return (0);
}