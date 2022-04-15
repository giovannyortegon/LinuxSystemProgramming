#include<string.h>
#include<stdio.h>

int main(void)
{
	char a[] = "Hello";
	char *b;

	b = strdup(a);

	printf("b = %s", b);

	return (0);
}
