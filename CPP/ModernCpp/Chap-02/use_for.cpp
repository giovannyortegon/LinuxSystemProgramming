#include<iostream>

int main() {
    auto arr = {1, 2, 3, 4, 5};

    for (auto x: arr) {
        std::cout<< x <<" "  <<std::endl;
    }

    auto &&range = arr; 
    // auto begin = std::begin(arr);
    auto begin = std::begin(range);
    std::cout <<begin <<" ";
    // auto end = std::end(arr);
    auto end = std::end(range);
    std::cout <<end <<" ";

    for (; begin != end; ++begin) {
        auto v = * begin;
        std::cout <<v <<" ";
    }
    std::cout <<std::endl;
    return (0);

}