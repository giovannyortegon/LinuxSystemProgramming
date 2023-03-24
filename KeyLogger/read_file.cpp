#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  ifstream read("file.txt");
  string x;

  read >> x;

  cout <<x <<endl;

  read.close();

  return (0);

}
