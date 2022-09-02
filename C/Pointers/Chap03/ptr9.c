#include<stdio.h>
#include<stdlib.h>

int *ptr = NULL;
static int count = 0;

void insert(int data);
void show();

int main(int argc, int *argv[]) {
    int c = 0;
    int data;

    while (c != 3) {
        printf("Insert choice\n");
        printf("1 to Insert data\n");
        printf("2 to Show data\n");
        printf("3 to quit data\n");
        scanf("%d", &c);

        if (c == 3) {
            break;
        }

        switch (c) {
        case 1:
            printf("Data = ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Data in array\n");
            show();
            break;
        default:
            printf("Not allowed option!\n");
            break;
        }
        fflush(stdin);
    }

    return (0);
}
void insert(int data) {
    if(ptr == NULL) {
        ptr = (int *) malloc(sizeof(int));
        ptr[0] = data;
    } else {
        ptr = (int *) realloc(ptr, sizeof(int) * (count+1));
        ptr[count] = data;
    }
    count++;
}
void show() {
    int i = 0;

    for (; i < count; i++) {
        printf("%d\n", ptr[i]);
    }
}