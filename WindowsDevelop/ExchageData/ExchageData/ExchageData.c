#include <stdio.h>

int main()
{
	int a = 20, b = 50;

	printf("Before exchange\na: %d b: %d", a, b);

	__asm {
		push a;
		push b
		pop a;
		pop b;
	}
	printf("\nExchange: ");
	printf("\na: %d b: %d\n", a, b);
}
