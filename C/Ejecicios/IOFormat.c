#include<stdio.h>

int main() {
    int i = 10;
    char ch = 'A';
    float a = 3.4;
    char str[20];

    printf("\n%d %c %f", i, ch, a);
    sprintf(str, "%d %c %f", i, ch, a);
    printf("\n%s", str);

    return (0);
}
