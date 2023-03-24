#include<iostream>
#include<vector>

int main() {
    std::vector<int> arr = {2, 3, 5};
    std::vector<int>::iterator ptr;

    std::cout <<"The elements of vector: " <<std::endl;

    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
        std::cout <<* ptr <<" ";
    }

    std::cout <<std::endl;
    return (0);
}