#include<iostream>
#include<string>

// Class
class house {
    private:
        // member variable
        int length = 0;
        int breadth = 0;
    
    public:
    // member functions
        void setData(int x, int y) {
            length = x;
            breadth = y;
        }
        void area() {
            std::cout <<"Area of house is " << length * breadth <<"\n";
        }
};

int main(void) {
    house h1;

    h1.setData(500, 600);
    h1.area();
    return (0);

}