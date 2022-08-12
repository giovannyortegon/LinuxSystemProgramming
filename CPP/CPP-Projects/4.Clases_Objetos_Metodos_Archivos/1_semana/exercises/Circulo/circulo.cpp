#include<iostream>
#include"circulo.h"

using namespace std;

int main()
{
	Circulo A;
	double area;

	A.setRadio(10);
	area = A.CalcArea();

	cout <<area <<endl;

	return (0);
}
