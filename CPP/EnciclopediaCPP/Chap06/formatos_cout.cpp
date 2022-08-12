#include<iostream>

using namespace std;

int main(void)
{
	int v = 165;

	cout <<"165 in hexadecimal is: \n";

	cout.setf(ios::hex, ios::basefield );
	cout.width(10);
	cout <<v <<endl;

	return (0);
}
