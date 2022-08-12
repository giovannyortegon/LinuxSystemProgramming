#include<iostream>
#include<cctype>

using namespace std;

int main()
{
	char ch;
	int count;

	while (cin >> noskipws >> ch)
	{
		if (isalpha(ch))
		{
			count++;
		}
		ch = toupper(ch);
		cout << ch;
	}

	cout <<"The count of alphabetic charaters is: " << count;

	return (0);
}
