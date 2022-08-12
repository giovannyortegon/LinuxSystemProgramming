#include<iostream>

using namespace std;

void permutar(int &, int &);

int main() {
    int a = 10, b = 20;

    cout <<"a = " <<a <<", b = " <<b <<endl;

    permutar(a, b);

    cout <<"a = " <<a <<", b = " <<b <<endl;

    return (0);
}
void permutar(int &rx, int &ry) {
    int z = rx;

    rx = ry;
    ry = z;
}