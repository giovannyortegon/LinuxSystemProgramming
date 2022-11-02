#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> num(3,0);
    int sum ;
    
    for (auto i = 0; i < num.size(); i++) {
        cin >> num[i];
        sum += num[i];
    }
    
    cout <<endl <<sum<<endl;
    
    return 0;
}
