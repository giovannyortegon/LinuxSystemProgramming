#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char number[13]="\0";
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void convertir_binario(int n);
void binary(char c, int n);
int n_primos(int n);

int main(int argc, char *argv[]) {
	
	int space = 0;
	int count = 0;
	int num = 0;
	printf("\t\t");
	for (int i = 12; i >= 0; i--)
		printf("%d ", (i << 1));
	printf("\n");

	for (int i = 2; i < 1500; i++) {
		num = n_primos(i);
		if (num) {
			convertir_binario(i);
			printf("| %d\t |-> |\t", i);
			for (int i = 0; i < 12; i++)
				printf("%c ",number[i]);
			count++;
			printf("|\n");
			for (int line = 0; line <= 40; line++)
				printf("-");
			printf("\n");
//			printf("--\t--\t--\t--\t--\t-\n");
		}
	}	
	printf("\n\nImprimio:\t%d\n", count);
	return 0;
}

void convertir_binario(int n) {
	int b = 0;
	char bit = '\0';

	for (int i = 0; i < 12; i++) {
		b = n & (1 << i);
		bit = ( b != 0 ? '1': '0');
//		printf("%c ", bit);
		binary(bit, i);
	}
	number[13]='\0';
}

void binary(char c, int n) {
	char tmp = '\0';
	int next;

	if (n == 0) {
		number[0] = c;
		return;
	}

	for (int j = n; j > 0; j--) {
		next = j;
		number[j] = number[--next];
	}
	number[0] = c;
}

int n_primos(int n){
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
