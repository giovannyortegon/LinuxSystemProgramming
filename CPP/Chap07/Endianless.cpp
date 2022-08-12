#include<iostream>
#include<bit>

int main() {
    if (std::endian::native == std::endian::big)
        std::cout << "big" <<std::endl;
    else if (std::endian::native == std::endian::little)
        std::cout << "little" <<std::endl;

    return (0);
}