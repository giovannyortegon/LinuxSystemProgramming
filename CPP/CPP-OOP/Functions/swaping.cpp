#include<iostream>

using namespace std;

void swap(int &fst, int &snd);

int main()
{
	int first = 10;
	int second = 20;

	swap(first, second);

	cout <<"Value of first ina main: " <<first <<endl;
	cout <<"Value of second in main: " <<second <<endl;

	return (0);
}
void swap(int &fst, int &snd)
{
	int temp = fst;
	fst = snd;
	snd = temp;

	return;
}
