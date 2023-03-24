#include<iostream>
#include<fstream>

using namespace std;


int main()
{
  ofstream write("file.txt");

  write <<"WIndows is awesome" <<endl;

  write.close();

  return (0);
}
