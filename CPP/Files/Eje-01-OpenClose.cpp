#include<iostream>
#include<fstream>

int main() {
    std::fstream fh;

    fh.open("./test.txt", std::ios::app);
    if (fh.is_open()) {
        fh <<"This is sample text." <<std::endl;
        fh.close();
    }

    return (0);   
}