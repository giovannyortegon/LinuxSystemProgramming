/* A function that short an array of inttegers and
 * counts the number of interchanges made in the process.
 */
#include<stdio.h>

static int count = 0;

/* return true if interchanges are made */
static int onepass(int * a, int n) {
    int i;
    int interchanges;
    int temp;

    for (i = 0; i < n -1; i++) {
        if(a[i] > a[i + 1]) {
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            interchanges = 1;
            count++;
        }
    }
    return (interchanges);
}

void clearcount(void) {
    count = 0;
}

int getcount(void) {
    return (count);
}

void bubblesort(int * a, int n) {
    int i;
    
    for (i = 0; i < n - 1; i++) {
        if (!onepass(a, n - 1))
            break;
    }
}

int main() {
    int i;
    int a[6] = {15, 3, 6, 2, 7, 1};

    for (i = 0; i < 6 - 1; i++) {
        printf("%d ", a[i]);
    }

    count+=20;
    puts("\n");

    // clearcount();
    bubblesort(a, 6);

    for (i = 0; i < 6 - 1; i++) {
        printf("%d ", a[i]);
        // printf("%d", getcount());
    }
    puts("\n");

    return (0);
}