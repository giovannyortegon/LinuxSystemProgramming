#include<iostream>
#include<string>

int main() {
    std::string s1 {"Inicio programacion"} ;
    std::string s2;
    std::string s3;

    std::getline(std::cin, s2);
    std::cout <<s1 <<std::endl;
    std::cout <<s2 <<std::endl;

    s3 = "C++";
    s1 += s3;
    std::cout <<s1 <<std::endl;

    int n = s1.find("C++");
    std::cout << n <<std::endl;
    if (n != std::string::npos)
        std::cout <<s1.substr(n, s1.size()) <<std::endl;

    return (0);
}