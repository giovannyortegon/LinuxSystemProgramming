#include<stdio.h>

int func(int);

int main() {

	int a = 10;
	int res = func(a);

	printf("%d\n\n", res);

	return (0);
}

int func(int x) {
	int b = 20;
	b += x;

	return (b);
}