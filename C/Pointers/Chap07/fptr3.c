#include<stdio.h>

int arraysearch(int data) {
    return 1;
}

int linkedlistsearch(int data) {
    return 1;
}
int binarysearch(int data) {
    return 1;
}

int search(int(* funptr)(int), int data) {
    return (*funptr)(data);
}

int main(int argc, char * argv[]) {
    printf("Input Option:\n");
    printf("1. arraysearch\n");
    printf("2. linkedlistsearch\n");
    printf("3. binarysearch\n");
    printf("4. exit\n");

    int choice = 0;
    int data;

    while (choice != 4) {
        printf("Input\n");
        scanf("%d", &choice);
        printf("Data to search\n");
        scanf("%d", &data);

        if (choice == 1) {
            search(arraysearch, data);
        } else {
            search(linkedlistsearch, data);
        } else if (choice == 3) {
            search(binarysearch, data);
        } else if (choice == 4) {
            break;
        }
    }

    return (0);
}