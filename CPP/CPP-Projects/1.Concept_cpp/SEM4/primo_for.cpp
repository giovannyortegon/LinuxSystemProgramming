#include<iostream>

using namespace std;

int main()
{
	int a = 1;
	int primo = 0;
	int residuo = 0, contador = 0;

	cout<<"Digite un numero y averigue si es primo "<<endl;
	cin>>primo;

	for (a = 1; a < primo; a++)
	{
		residuo = primo / a;

		if (residuo * a == primo)
		{
			contador++;
		}
	}

	if (contador <= 2)
	{
		cout<<"El numero "<< primo<<" es primo"<<endl;
	}
	else
	{
		cout<<"El numero "<< primo<<" no es primo"<<endl;
	}
}
