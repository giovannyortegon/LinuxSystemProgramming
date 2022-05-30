#include<stdio.h>

int main(int argc, char * argv[]) {
    int arr[4] = {1,2,3,4};
    int * arr_ptr[4];
    int i;

    for (i = 0; i < 4; i++) {
        arr_ptr[i] = arr + i;
    }

    printf("Address of (arr) array elements\n");

    for (i = 0; i < 4; i++) {
        printf("Address of %d index = %p\n", i, arr + i);
    }
    
    printf("\nValue of (arr_ptr) array elements\n");
    for (i = 0; i < 4; i++) {
        printf("Value of %d index = %p\n", i, arr_ptr[i]);
    }
    printf("\n");
    for (i = 0; i < 4; i++) {
        printf("Value of %d index = %d\n", i, *arr_ptr[i]);
    }
    return (0);
}