#include"single_list.h"
/**
 * @brief 
 * 
 * @param value 
 * @param head 
 * @return * void 
 */
void insert_end(int value, SList ** head) {
    SList * node = NULL, * cpy_list = NULL;

    node = new_node(value);

    if (*head == NULL) {
        * head = node;
        return;
    } else {
        cpy_list = (* head);
        while (cpy_list->next != NULL) {
            cpy_list = cpy_list->next;
        }
        cpy_list->next = node;
    }
}

SList * new_node(int value) {
    SList * node = (SList *) malloc(sizeof(SList));
    node->value = value;
    node->next = NULL;

    return node;
}

void free_list(SList ** head) {
    SList * next;
    SList * curr = (*head);

    while (curr != NULL) {
       next = curr->next;
       free(curr);
       curr = next; 
    }
}

void print_list(SList * list) {

    printf("*****************\n");
    printf("|");
    while (list != NULL){
        printf("-> | %d |-| ", list->value);
        list = list->next;
    }
    printf("->NULL\n");
    printf("*****************\n");
}
