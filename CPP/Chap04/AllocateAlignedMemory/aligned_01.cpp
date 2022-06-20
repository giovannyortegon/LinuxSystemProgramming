#include<iostream>
#include<type_traits>

int main() {
    std::cout <<"int alignment = " <<std::alignment_of<int>::value <<std::endl;
    std::cout <<"double aligment = " <<std::alignment_of<double>::value <<std::endl;
    
    return (0);
}