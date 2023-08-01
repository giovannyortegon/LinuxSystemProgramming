#include<stdio.h>

//void func1();
//void func2();
//
//#pragma stratup func1
//#pragma exit func2
//
//void main() {
//	printf("\nInside main");
//}
//
//void func1() {
//	printf("\nInside func 1");
//}
//void func2() {
//	printf("\nInside func 2");
//}

#pragma warn –rvl /* return value */
#pragma warn –par /* parameter not used */
#pragma warn –rch /* unreachable code */
int f1()
{
	int a = 5;
}
void f2(int x)
{
	printf("\nInside f2");
}
int f3()
{
	int x = 6;
	return x;
	x++;
}

void main()
{
	f1();
	f2(7);
	f3();
}