#include<iostream>

using namespace std;

int main() {
    int lista[] = {24, 30 , 15, 45, 34};
    int * plista = lista;

    for (int ind = 0; ind < 5; ind++) {
        cout <<*plista++ <<endl;
    }
    cout <<endl;
}