/* interest.c */
#include<stdio.h>
#include<math.h>

int main(void)
{
	int years = 15;
	int savings = 99000;
	float interest = 1.5;

	printf("The total savings after %d years "
		   "is %.2f\n", years, savings * pow(1 + (interest/100),  years));


	return (0);
}
