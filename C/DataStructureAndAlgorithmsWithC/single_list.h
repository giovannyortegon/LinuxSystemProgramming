#ifndef __SINGLE_LIST__
#define __SINGLE_LIST__

#include<stdio.h>
#include<stdlib.h>


typedef struct single_list {
    int value;
    struct single_list * next;
} s_list;

s_list * new_node(int value);
void push_heap(s_list ** list, int value);
void push_end(s_list ** list, int value);
void push(s_list ** list, int value, int position);
void pop_heap(s_list ** list);
void pop_end(s_list ** list);
void pop(s_list ** list, int position);
void print_list(s_list * s_list);
void free_list(s_list ** list);
int size_list(s_list * list);

#endif /*__SINGLE_LIST__ */