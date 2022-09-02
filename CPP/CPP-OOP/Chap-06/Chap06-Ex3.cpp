#include<iostream>

using namespace std;

typedef int Item;

class LinkListElement {
    private:
        void * data;
        LinkListElement * next;

    public:
        LinkListElement() { data = 0; next = 0; }
        LinkListElement(Item * i) { data = i; next = 0; }
        ~LinkListElement() { delete (Item *)data; next = 0; }
        void * GetData() { return data; }
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
};

LinkList::LinkList() {
    head = tail = current = 0;
}

LinkList::LinkList(LinkListElement * element) {
    head = tail = current = element;
}

void LinkList::InsertAtFront(Item * theItem) {
    LinkListElement * temp = new LinkListElement(theItem);
    temp->SetNext(head);
    head = temp;
}

LinkListElement * LinkList::RemoveAtFront() {
    LinkListElement * remove = head;
    head = head->GetNext();
    current = head;

    return remove;
}
void LinkList::DeleteAtFront() {
    LinkListElement * deallocate;

    deallocate = RemoveAtFront();
    delete deallocate;
}

void LinkList::Print() {
    Item output;

    if (!head) {
        cout <<"<Empty>";
    }

    current = head;
    while (current)     {
        output = * ((Item *) current->GetData());
        cout <<output <<" ";
        current = current->GetNext();
    }
    cout <<endl;
}

LinkList::~LinkList() {
    while (!IsEmpty())
        DeleteAtFront();
}

class Stack: private LinkList {
    private:

    public:
        Stack() : LinkList() {}
        ~Stack() { }
    // the public interface for stack
    void Push(Item * i) { InsertAtFront(i); }
    Item * Pop();
    int IsEmpty() { return LinkList::IsEmpty(); }
    void Print() { LinkList::Print(); }
};
Item * Stack::Pop() {
    LinkListElement * temp;
    temp = RemoveAtFront();

    // copy temp's data
    Item * item = new Item(*((Item *) temp->GetData()));
    delete temp;

    return item;
}

int main() {
    Stack stack1;

    stack1.Push(new Item(3000));
    stack1.Push(new Item(600));
    stack1.Push(new Item(475));

    cout <<"Stack 1: ";
    stack1.Print();

//    stack1.RemoveAtFront();  // inaccessible. only scope of LinkList class

    while (!(stack1.IsEmpty())) {
        stack1.Pop();
        cout <<"Stack 1 after popping an item: ";
        stack1.Print();
    }

    return (0);
}