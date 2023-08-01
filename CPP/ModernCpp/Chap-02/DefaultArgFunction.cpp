#include<iostream>

void CreateWindows(const char * title, int x = -1, int y = -1, int width = -1, int height = -1);

int main() {
    CreateWindows("Windows");
    CreateWindows("Windows", 299, 400);

    return (0);
}
void CreateWindows(const char * title, int x, int y, int width, int height) {
    std::cout <<std::endl <<"Title: " <<title <<std::endl;
    std::cout <<"X: " <<x <<std::endl;
    std::cout <<"Y: " <<y <<std::endl;
    std::cout <<"Width: " <<width <<std::endl;
    std::cout <<"Height: " <<height <<std::endl;
}