#include<iostream>

inline int Squared(int x);

// #define Squared(x) x * x   // no evaluate the argument a + 1 = 11 correct is 36

int main() {
    int a = 5;
    // int result = Squared(a);
    int result = Squared(a + 1);

    std::cout <<result <<std::endl;

    return (0);
}

int Squared(int x) {
    return (x * x);
}