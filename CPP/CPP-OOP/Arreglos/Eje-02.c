#include<iostream>
#include<cstring>

int main() {
    const int n = 3;
    int ** arreglos = new int*[n];

    for(int i = 0; i < n; i++)
        arreglos[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arreglos[i][j] = i;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++)
            std::cout <<arreglos[i][j] <<" ";
        std::cout<<std::endl;
    }
    std::cout <<std::endl;
    
    for(int i = 0; i < n; i++)
        delete arreglos[i];

    delete arreglos;

    return (0);
}