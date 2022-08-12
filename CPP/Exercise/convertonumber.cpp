#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(void)
{
	string stringLength;
	float inches = 0;
	float yardage = 0;

	cout <<"Enter number of inches: ";
	getline(cin, stringLength);

	stringstream(stringLength) >> inches;
	cout <<"You entered: " <<inches <<"\n";

	yardage = inches / 36;

	cout << "Yardage is: " << yardage;

	return (0);
}
