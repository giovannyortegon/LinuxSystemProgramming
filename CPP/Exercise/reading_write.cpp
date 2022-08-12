#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char * argv[])
{
	string line;

	ofstream FileIn ("input.txt", ios::app);
	if (FileIn.is_open())
	{
		FileIn <<"\nAdding a line\n";
		FileIn <<"More lines\n";
		FileIn.close();
	}
	else
		cout <<"Unable to open file for writting.";

	ifstream FileOut ("input.txt");
	if (FileOut.is_open())
	{
		while (getline(FileOut, line))
		{
			cout <<line <<'\n';
		}
		FileOut.close();
	}
	else
		cout <<"Unable to open file for reading\n";

	return (0);
}
