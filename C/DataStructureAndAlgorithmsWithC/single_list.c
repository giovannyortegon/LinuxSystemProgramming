#include"single_list.h"

s_list * new_node(int value) {
    s_list * node = NULL;

    node = (s_list *)malloc(sizeof(s_list));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

void push_heap(s_list ** list, int value) {
    s_list * tmp, * new;

    new = new_node(value);

    if ((*list) == NULL) {
        (*list) = new; 
        return;
    } else {
        tmp = (*list);

        new->next = tmp;
        tmp = new;
        (*list) = tmp;
    }
}

void push_end(s_list ** list, int value) {
    s_list * tmp, * new;

    new = new_node(value);

    if ((*list) == NULL) {
        (*list) = new; 
        return;
    } else {
        tmp = (* list);

        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new;  
    }
}
void push(s_list ** list, int value, int position) {

    int size = size_list(*list);


    if (size == 0 && position == 0) {
        push_heap(&(*list), value);    
        return;
    }
    if (position > size) {
        fprintf(stderr, "[x] Error supera el largo de la lista.\n");
        return;
    }
    if (size == position) {
        push_end(&(*list), value);
        return;
    }
    s_list * tmp, * new, *next;
    int pos = 1;
    tmp = (*list);      // Copy list to tmp
    next = tmp;         // Copy tmp to next

    next= tmp->next;    // increment a next node

    while (tmp != NULL)     // iteration of list tmp
    {
       if (pos == position) // if match pos with position goout of the iteration
            break;
        tmp = tmp->next;    // next node of tmp
        next= tmp->next;    // next node of next
       pos++;               // increment position
    }

    new = new_node(value);  // create a new node

    new->next = next;
    tmp->next = new;
}

int size_list(s_list * list) {
    int size = 0;

    if (list == NULL) {
        return 0;
    }

    while (list != NULL) {
        ++size;
        list = list->next;
    }
    
    return size;
}

void pop_heap(s_list ** list) {
    s_list * tmp;

    tmp = (*list);

    (*list) = (*list)->next;

    free(tmp);
}

void pop_end(s_list ** list) {
    s_list * tmp, * before;
    before = (*list);
    tmp = before;

    tmp = tmp->next;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        before = before->next;
    }

    free(tmp);
    before->next = NULL;
}

void pop(s_list ** list, int position) {

    int size = size_list(*list);

    if (size == 0 && position == 0) {
        pop_heap(&(*list));    
        return;
    }
    if (position > size) {
        fprintf(stderr, "[x] Error supera el largo de la lista.\n");
        return;
    }
    if (size == position) {
        pop_end(&(*list));
        return;
    }

    s_list * tmp, * next, * del;
    int pos = 1;

    tmp = (* list);
    next = tmp->next;

    while (tmp != NULL) {
        if (pos == position)
            break;
        tmp = tmp->next;
        next = tmp->next;
        pos++;
    }
    del = next;
    next = next->next;

    tmp->next = next;
    free(del);
}

void print_list(s_list * list) {
    printf("|HEAD|-");
    while (list != NULL) {
        printf("| %d ||->", list->value);
        list = list->next;
    }
    printf("NULL\n");

}

void free_list(s_list ** list) {
    s_list * tmp = (*list);
    s_list * next = NULL;

    while(tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;     
    }
}