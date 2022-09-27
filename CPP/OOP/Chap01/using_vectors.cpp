#include<iostream>
#include<vector>

int main() {
    int t, x;
    std::cout <<"N de elementos: ";
    std::cin >> t;
    std::cout <<"Valor inicial: ";
    std::cin >> x;

    std::vector<int> v1(t, x);
    std::cout <<std::endl;

    // mostrar v1
    for (auto e : v1) {
        std::cout <<e <<" ";
    }
    std::cout <<std::endl;

    return (0);
}