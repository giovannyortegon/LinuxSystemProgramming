#include"list.h"


Node::Node() {}
Node::Node(int data):Data{data}, Next(NULL) {}

List::List() {}
List::~List() {}

void List::Inset_Head(int data) {
    Node * tmp = head;
    Node * node = new Node(data);

    if (count == 0) {
        head = node;
    }

    node->Next = tmp;
    head = node;

    count++;
}

void List::Inset_End(int data) {
    Node * tmp = head;
    Node * node = new Node(data);

    while (tmp->Next != NULL) {
        tmp = tmp->Next;
    }

    tmp->Next = node;

    count++;
}

int List::Count() {
    return count;
}

void List::Print_list() {
    Node * node = head;

    std::cout <<"Head" <<std::endl;
    std::cout <<"  | " <<std::endl;
    std::cout <<"   -> " ;
    while (node != NULL) {
        std::cout << node->Data <<"->";
        node = node->Next;
    }
    std::cout <<"NULL"<<std::endl;
}

void List::Inset_Before(int index, int data) {
    Node * next;
    Node * curr = head;
    int i = 1;

    Node * node = new Node(data);

    if (index > count) {
        std::cout <<"[x] Error: No es posible agregar" <<std::endl;
        return;
    }

    if (count == 0) {
        head = node;
        return;
    }

    while (curr != NULL) {
        next = curr->Next;
        if (i == index)
            break;

        curr = next;
        i++;
    }

    curr->Next = node;
    node->Next = next;

    count++;
}

void List::Inset_After(int index, int data) {
    Node * next, * curr = head;
    Node * node = new Node(data);
    int i = 0;

    if (count == 0) {
        Inset_Head(data);
        return;
    }

    while (curr != NULL) {
        next = curr->Next;
        if (i == index) {
            break;
        }
        curr = next;
        i++;        
    }

    curr->Next = node;
    node->Next = next;

    count++;    
}

void List::RemoveAll() {
    Node * next;
    Node * curr = head;

    while (curr != NULL) {
        next = curr->Next;
        delete curr;
        curr = next;
    }
}