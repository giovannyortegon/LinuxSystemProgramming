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
        Node * heap;    
        Node * tail;
        void Inset_Head(int data);
        int Count();
        void Print_list();
        void RemoveAll();
};

#endif // __LIST_H__