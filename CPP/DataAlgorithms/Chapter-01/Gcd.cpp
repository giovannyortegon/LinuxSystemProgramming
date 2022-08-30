#include<iostream>

unsigned int gcd(unsigned int const a, unsigned int const b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    unsigned int result = 0;

    result = gcd(20, 30);

    std::cout <<"Result: " <<result <<std::endl;

    return (0);
}