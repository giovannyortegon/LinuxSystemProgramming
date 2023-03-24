#include<iostream>

using namespace std;

int main()
{
	int num = 10;
	int *ptr;

	ptr = &num;


	cout <<endl <<"Printed from num variable" <<endl;
	cout <<"num addres: " <<&num <<endl;
	cout <<"num value: " <<num <<endl;

	cout <<endl <<"Printed from ptr pointer" <<endl;
	cout <<"num addres: " <<ptr <<endl;
	cout <<"num value: " <<*ptr <<endl;

	return (0);
}
