#include<stdio.h>

//void fun(int y); // pass by value
void fun(int *y);

int main()
{
	int x = 10;

	fun(&x);

	printf("Value of x in main: %d\n", x);

	return (0);
}
//void fun(int y)  // pass by value
void fun(int *y) 	// pass by reference
{
	(*y)++;
	printf("Value of y in Fun: %d\n", *y);

	return;
}
