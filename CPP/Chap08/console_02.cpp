#include<iostream>
#include<string>

int main() {
    std::string fullNameWithCin;
    std::cout <<"Full name got with cin: ";
    std::cin >> fullNameWithCin;

    std::cout <<"Hello " <<fullNameWithCin <<std::endl;

    return (0);
}