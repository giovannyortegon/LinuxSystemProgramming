#include<iostream>


unsigned int gcd(unsigned int const a, unsigned int const b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    int h = gcd(a, b);
    return abs(a * b) / h; 
}

int main() {
    int result = 0;

    result = lcm(20, 30);

    std::cout <<"Result: " <<result <<std::endl;

    return (0);
}