#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data,
    struct node * next;
} SLinkedList;


int main() {
    SLinkedList * List, * new_node;

    new_node = createNode(8);
    if new



}



SLinkedList * createNode(int data) {
    SLinkedList * new = (SLinkedList *)malloc(sizeof(SLinkedList));
    if (new == NULL) {
        fprintf(stderr, "[!] Error creating node.");
        return NULL;
    }

    new->data = data;
    new->next = NULL;

    return new;
}