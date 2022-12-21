#include<iostream>

int main() {
    std::string s;

    std::cout <<"Enter string: ";
    std::getline(std::cin, s);

    std::cout <<"You have entered: ";
    std::cout <<std::endl;

    s.push_back('Y');
    std::cout <<"After using push back: " <<s <<std::endl;

    s.pop_back();
    std::cout <<"After using pop back: " <<s <<std::endl;

}