// f(0) = 0, f(1) = 1, f(n) = f(n - 1) + f( n + 2)
#include<iostream>
#include<cstring>

int fibonacci(int n);

int suma(int a, int b);

int main() {

    int num;

    int (*f)(int, int);

    f = suma;

    std::cout <<&suma <<std::endl;
    std::cout <<f <<std::endl;

    std::cout << f(1, 3) <<std::endl;
    std::cout <<"Enter number: ";
    std::cin >> num;

    for(int i = 0; i < num; i++)
        std::cout <<fibonacci(i) <<" ";

    std::cout <<std::endl;

    return (0);
}

int fibonacci(int n) {
    if (n <= 1)
        return (1);
    else {
        return fibonacci(n -1) + fibonacci(n - 2);
    }
}

int suma(int a, int b) {
    return a + b;
}