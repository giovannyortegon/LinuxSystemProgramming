#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int a;

	cout<<"Digite un valor para la variable a: ";
	cin>>a;
	
	switch(a)
	{
		case 0:
			cout<<"case 0"<<endl;
			break;
		case 1:
			cout<<"caso 1"<<endl;
			break;
		case 2:
			cout<<"caso 2"<<endl;
			break;
		case 3:
			cout<<"caso 3"<<endl;
			break;
	}
	return 0;
}
