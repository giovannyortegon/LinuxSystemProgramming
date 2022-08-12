#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int a, b, c, h;

	a = 4;
	b = 0;
	c = 0;
	h = 0;

	if (a > b)
	{
		c = 3;
		a = 0;
	}
	else if (a == 4)
	{
		h = 5;
		b = 0;
	}
	cout<<"a = "<<a<<" b = "<<b <<" c = "<<c<<" h = "<<h<<endl;

	//cin>>a;
	//system("pause");

	return 0;
}
