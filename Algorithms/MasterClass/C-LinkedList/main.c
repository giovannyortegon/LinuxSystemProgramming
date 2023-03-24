#include"single_list.h"

int main() {
    SList * list;

    insert_end(29, &list);
    print_list(list);
    insert_end(230, &list);
    print_list(list);
    insert_end(30, &list);
    print_list(list);

    free_list(&list);

    return (0);
}
