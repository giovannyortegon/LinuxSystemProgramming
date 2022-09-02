#include<iostream>
#include<string>
#include<sstream>

int main() {
    std::istringstream ss("Giovanny, Ortegon, 43");

    std::string token;

    while (std::getline(ss, token, ',')) {
        std::cout <<token <<"\n";
    }
    
    return (0);
}