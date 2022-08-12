#include<iostream>
#include <climits>
#include<string>

using namespace std;

int main()
{
    string sCadena = "Lenguaje C++";
    char cMatrizCars[] = "abc";
    int dato_int = 4;
//    long dato_long = LONG_MIN;
    long dato_long = LONG_MAX;
    float dato_float = 3.40282347e+38F;
    double dato_double = 3.1415926;
    bool dato_bool = true;

    cout <<sCadena <<endl;
    cout <<cMatrizCars <<endl;
    cout <<dato_int <<endl;
    cout <<dato_long <<endl;
    cout <<dato_float <<endl;
    cout <<dato_double <<endl;
    cout <<boolalpha;
    cout <<dato_bool <<endl;

    return (0);
}
