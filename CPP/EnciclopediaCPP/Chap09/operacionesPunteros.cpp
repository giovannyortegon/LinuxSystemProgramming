#include<iostream>
#include <iterator>

int main() {
    int x[5] = {1,2,3,4,5};
    int b, *pa, *pb;


    x[3] = 10;

    pa = &x[0];
    pb = &x[0];

    std::cout <<"pa = "<<std::endl;
    for (int i = 0; i < 5; i++)
        std::cout <<i <<" "<<*(pa + i)<<" " <<pa + i <<std::endl;
    std::cout <<std::endl;

    std::cout <<"pb" <<std::endl;
    for (int i = 0; i < 5; i++)
        std::cout <<i <<" "<<*(pb + i)<<" " <<pb + i<<std::endl;
    std::cout <<std::endl;

    b = *pa + 1;
    std::cout <<"b =  *pa + 1 = " <<b <<pa <<std::endl;

    b = *(pa + 1);
    std::cout <<"b = *(pa + 1) = " <<b <<std::endl;

    std::cout <<*pb <<" " <<pb <<std::endl;
    (*pb)--;
    std::cout <<"(*pb)-- = " <<*pb <<std::endl;

    std::cout <<*pb <<" " <<pb <<std::endl;
    x[0] = *pb--;
    std::cout <<*pb <<" " <<pb <<std::endl;
    std::cout <<"x[0] = *pb-- = " <<x[0] <<std::endl;

    return (0);
}