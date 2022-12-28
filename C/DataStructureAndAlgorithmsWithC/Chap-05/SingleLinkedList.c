#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s_list{
    int data;
    struct s_list * next;
}single_list;

single_list * create_node(int data);

void free_list(single_list ** head);
void add_node_begning(single_list ** head, int data);
void add_node_end(single_list ** head, int data);
void add_before(single_list ** head, int index,int data);
void add_afer(single_list ** head, int index,int data);
void print_list(single_list * head);

int main() {
    single_list * List, * new_node;

    add_node_begning(&List, 1);
    print_list(List);

    add_node_end(&List, 8);
    add_node_end(&List, 7);
    add_node_end(&List, 20);
    add_node_end(&List, 2);
    print_list(List);

    add_node_begning(&List, 3);
    add_node_begning(&List, 4);
    print_list(List);

    add_afer(&List, 2, 45);
    add_afer(&List, 1, 57);
    print_list(List);


    add_before(&List, 2, 27);
    add_before(&List, 1, 0);
    add_before(&List, 3, 114);
    print_list(List);
    // Free List
    free_list(&List);

    return (0);
}

single_list * create_node(int data) {
    single_list * new;

    new = (single_list *)malloc(sizeof(single_list));
    if (new == NULL) {
        fprintf(stderr, "[!] Memory not available.");
        return NULL;
    }

    new->data = data;
    new->next = NULL;

    return new;
}
void print_list(single_list * node) {

    while (node != NULL) {
        //printf("List: %p\n",head);
        printf("node->%d ", node->data);
        node = node->next;
    }
    printf("node->next = null\n");
}

void add_node_begning(single_list ** head, int data) {
    single_list * tmp, * node;

    tmp = (* head);

    node = create_node(data);
    if (node == NULL) {
        fprintf(stderr, "[x] Node error.\n");
        return;
    }

    if (*head == NULL) {
        (*head) = node;
        return;
    }

    node->next = tmp;
    *head = node;
}

void add_node_end(single_list ** head, int data) {
    single_list * tmp, * node;

    node = create_node(data);
    // printf("%d ", node->data);
    if (node == NULL) {
        fprintf(stderr, "[x] Error.");
    }

    if (*head == NULL) {
        *head = node;
        return;
    }

    tmp = (*head);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = node;
}

void add_afer(single_list ** head, int index,int data) {

    single_list * node, * curr, * next;
    int i = 1;

    node = create_node(data);

    if (*head == NULL){
        (*head) = node;
        return;
    }

    curr = (* head);

    while(curr != NULL) {
        next = curr->next;
        if (index ==  i)
            break;
        curr = next;
        i++;
    }

    node->next = next;
    curr->next = node; 
}
void add_before(single_list ** head, int index,int data) {
    single_list * node, * curr, * next;
    int i = 2;

    if (index == 1) {
        add_node_begning(&(*head), data);
        return;
    }

    node = create_node(data);

    if ((*head) ==  NULL) {
        (*head) = node;
        return;
    }

    curr = (*head);

    while (curr != NULL) {
        next = curr->next;
        if (i == index)
            break;
        curr = next;
        i++;
    }
    
    node->next = next;
    curr->next = node; 
}

void free_list(single_list ** head) {
    single_list * next;
    single_list * current = (*head);

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}