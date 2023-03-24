#ifndef _SINGLE_LIST_
#define _SINGLE_LIST_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct s_list {
    int value;
    struct s_list * next;
} SList;

SList * new_node(int value);
void free_list(SList ** head);
void print_list(SList * list);
void insert_end(int value, SList ** head);

#endif /* _SINGLE_LIST */