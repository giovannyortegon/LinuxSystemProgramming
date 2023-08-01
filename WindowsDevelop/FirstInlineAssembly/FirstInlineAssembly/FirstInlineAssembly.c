#include<stdio.h>

int main()
{
	int x, y, a, b;
	x = 2;
	y = 5;
	a = 23;
	b = 12;

	// x += 2
	__asm {
		//non-volatile register
		push ebx 

		mov eax, x
		mov ebx, y
		mov ecx, a
		mov edx, b
		imul eax, ebx
		sub ecx, edx
		add eax, ecx
		mov x, eax

		pop ebx
	}
	printf("Result: %d\n ", x);

	return (0);
}
