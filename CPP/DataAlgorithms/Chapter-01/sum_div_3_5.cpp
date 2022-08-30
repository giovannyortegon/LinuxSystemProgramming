#include<iostream>

int main() {
    unsigned int limit = 0;
    std::cout <<"Insert limit: ";
    std::cin >>limit;
    unsigned long long sum = 0;

    for (int i = 0; i < limit; i++) {
        if (i % 3 && i % 5) {
            // std::cout <<i <<std::endl;
            sum += i;
        }
    }

    std::cout <<"sum: " <<sum <<std::endl;

    return (0);
}