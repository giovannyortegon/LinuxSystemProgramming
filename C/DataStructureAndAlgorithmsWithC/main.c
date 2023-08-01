#include"single_list.h"

int main() {

    s_list * list = NULL, * tmp, * next;
    int size;

    size = size_list(list);
    printf("size: %d\n", size);

    push(&list, 40, 0);
    print_list(list);
    printf("\nsize: %d\n", size);

    push_heap(&list, 8);
    print_list(list);
    printf("\nsize: %d\n", size);

    push_heap(&list, 10);
    print_list(list);
    printf("\nsize: %d\n", size);

    push_heap(&list, 20);
    print_list(list);
    printf("\nsize: %d\n", size);

    push_end(&list, 50);
    print_list(list);
    printf("\nsize: %d\n", size);

    push(&list, 140, 5);
    print_list(list);
    printf("\nsize: %d\n", size);

    push(&list, 14, 2);
    print_list(list);

    size = size_list(list);
    printf("\nsize: %d\n", size);

    printf("\n************ DELETE NODE ************\n");

    size = size_list(list);
    printf("\nsize: %d\n", size);

    pop_heap(&list);
    print_list(list);
    printf("\nsize: %d\n", size);

    pop_end(&list);
    print_list(list);
    printf("\nsize: %d\n", size);

    pop_heap(&list);
    print_list(list);
    printf("\nsize: %d\n", size);

    pop(&list, 1);
    print_list(list);

    size = size_list(list);
    printf("\nsize: %d\n", size);

    free_list(&list);

    return (0);
}