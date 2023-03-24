#include<iostream>

int main() {
    int i = 7;
    int j = 10;

    std::cout <<"i : " <<i <<std::endl;
    std::cout <<"j : " <<j <<std::endl;

    std::swap(i, j);

    std::cout <<"i : " <<i <<std::endl;
    std::cout <<"j : " <<j <<std::endl;

    return (0);
}