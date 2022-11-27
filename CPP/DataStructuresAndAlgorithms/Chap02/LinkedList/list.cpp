#include"list.h"


Node::Node() {}
Node::Node(int data):Data{data}, Next(NULL) {}

List::List() {}
List::~List() {}

void List::Inset_Head(int data) {
    Node * tmp = heap;
    Node * node = new Node(data);

    if (count == 0) {
        heap = node;
    }


    node->Next = tmp;
    heap = node;

    count++;
}

int List::Count() {
    return count;
}

void List::Print_list() {
    Node * node = heap;

    std::cout <<"Head|->";
    while (node != NULL) {
        std::cout << node->Data <<"->";
        node = node->Next;
    }
    std::cout <<"NULL"<<std::endl;
}

void List::RemoveAll() {
    Node * next;
    Node * curr = heap;

    while (curr != NULL) {
        next = curr->Next;
        delete curr;
        curr = next;
    }
}