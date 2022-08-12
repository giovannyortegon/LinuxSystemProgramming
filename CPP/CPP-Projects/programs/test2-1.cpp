#include <iostream>
using namespace std;

int main(){
    int a = 3;
    int b = 8;
    int c = 12;

    int op1 = a && b;
    int op2 = c && a;
    int op3 = (b || c) && (!a || c);
    cout << "Op1: " << op1 << endl; 
    cout << "Op2: " << op2 << endl; 
    cout << "Op3: " << op3 << endl; 

    return 0;
}
