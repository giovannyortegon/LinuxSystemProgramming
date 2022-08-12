#include<iostream>

using namespace std;

double calcEarning(double rate, double hours=40);

int main()
{
	cout <<"Emplyee 1 pay: " <<calcEarning(22.0) <<endl;
	cout <<"Emplyee 2 pay: " <<calcEarning(12.50, 18) <<endl;

	return (0);
}
double calcEarning(double rate, double hours)
{
	double pay;

	pay = hours * rate;

	return (pay);
}
