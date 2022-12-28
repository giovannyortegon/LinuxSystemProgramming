#ifndef __LIST_H__
#define __LIST_H__

#include<iostream>

class Node {

    public:
        int Data;
        Node * Next;
        Node();
        Node(int data);
};

class List: public Node {
    private:
        int count;

    public:
        List();
        ~List();
        Node * head;    
        Node * tail;
        void Inset_Head(int data);
        void Inset_End(int data);
        void Inset_Before(int index, int data);
        void Inset_After(int index, int data);
        int Count();
        void Print_list();
        void RemoveAll();
};

#endif // __LIST_H__