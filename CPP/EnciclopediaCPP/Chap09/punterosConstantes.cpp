#include<iostream>

int main() {
    char a[] = "abcd";
    char * const d = a;
    // const char * b = a;

    // b[0] = 'e';      // error 
    // b = "xyz";
    d[0] = 'x';

    std::cout <<*d <<std::endl;



    return (0);
}