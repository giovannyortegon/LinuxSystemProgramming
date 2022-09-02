#include<iostream>

using namespace std;

typedef int Item;

class LinkListElement { // one 'node' or element in a LinkList
    private:
        void * data;
        LinkListElement * next;

    public:
        LinkListElement() {data = 0; next = 0; }
        LinkListElement(Item * i) { data = i; next = 0; }
        ~LinkListElement() { delete (Item *) data; next = 0; }
        void *GetData() { return data; }
        LinkListElement * GetNext() { return next; }
        void SetNext(LinkListElement * e) { next = e; }
};

class LinkList {
    private:
        LinkListElement * head;
        LinkListElement * tail;
        LinkListElement * current;

    public:
        LinkList();
        LinkList(LinkListElement *);
        ~LinkList();
        void InsertAtFront(Item *);
        LinkListElement * RemoveAtFront();
        void DeleteAtFront();
        int IsEmpty() { return head == 0; }
        void Print();
}