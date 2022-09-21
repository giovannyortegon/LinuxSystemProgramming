#include<iostream>
#include<iomanip>

template <typename T>
T max(T const a, T const b) {
    return a > b ? a : b;
}

struct foo {};

int main() {
    foo f1, f2;

    int a = max(1, 2);              // Ok
    double b = max(1.0, 2.0);          // Ok
    // max(f1, f2);            // Error for foo
    std::cout <<a <<std::endl;
    std::cout <<std::setprecision(4) <<b <<std::endl;

    return (0);
}