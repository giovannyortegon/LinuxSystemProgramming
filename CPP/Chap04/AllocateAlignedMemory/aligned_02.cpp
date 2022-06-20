#include<iostream>
#include<type_traits>

typedef std::aligned_storage<sizeof(int), 8>::type intAligned;

int main() {
    intAligned i, j;

    new(&i) int();
    new(&j) int();

    int * iu = &reinterpret_cast<int&>(i);
    *iu = 12;

    int * ju = &reinterpret_cast<int&>(j);
    *ju = 13;

    std::cout <<"alignment = " <<std::alignment_of<intAligned>::value <<std::endl;

    std::cout <<"value = " <<*iu <<std::endl;
    std::cout <<"value 2 = " <<reinterpret_cast<int&> (i) <<std::endl;
 
    return (0);
}