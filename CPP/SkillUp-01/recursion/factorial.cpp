#include<iostream>

int factorial(int n);

int main() {
    int num = 0;
    int result = 0;

    std::cout <<"Enter number: ";
    std::cin >> num;

    result = factorial(num);

    std::cout <<result <<std::endl;

    return (0);
}
int factorial(int n) {
    if (n != 0) {
        return n * factorial(n -1);
    }
    return 1;
}
