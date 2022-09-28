#include<iostream>
#include<cstring>

int main() {
    int n{3};

    int m[] ={2,3,4};

    std::cout <<n <<std::endl;

    int * arreglos = new int[3];

    for (int i = 0; i < 3; i++) {
        arreglos[i] = i;
    }

    for (int i = 0; i < 3; i++) {
        std::cout <<arreglos[i] <<" ";
    }
    std::cout <<std::endl;

    return (0);
}