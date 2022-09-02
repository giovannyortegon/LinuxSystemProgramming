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

        void InsertBeforeItem(Item *, Item *);
        LinkListElement * RemoveSpecificItem(Item *);
        void DeleteSpecificItem(Item *);
        void InsertAtEnd(Item *);
        LinkListElement * RemoveAtEnd();
        void DeleteAtEnd();

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

class Queue: protected LinkList {
    private:


    public:
        Queue(): LinkList() {}
        virtual ~Queue() {}         // we'll discuss virtual in Chp 7
        //public interface of Queue
        void Enqueue(Item *i) { InsertAtEnd(i); }
        Item * Dequeue();
        int IsEmpty() { return LinkList::IsEmpty(); }
        void Print() { LinkList::Print(); }
};

Item * Queue::Dequeue() {
    LinkListElement * temp;
    temp = RemoveAtFront();
    Item * item = new Item(*((Item *)temp->GetData()));
    delete temp;
    
    return (item);
}

class PriorityQueue: public Queue {
    private:
        /* data */
    public:
        PriorityQueue():Queue() { }
        virtual ~PriorityQueue() { }        // we'll see virtual in Chp 7
        void PriorityEnqueue(Item * i1, Item * i2) { InsertBeforeItem(i1, i2); }

};
int main() {
    Queue q1;

    q1.Enqueue(new Item(50));
    q1.Enqueue(new Item(67));
    q1.Enqueue(new Item(80));
    q1.Print();

    while (!(q1.IsEmpty())) {
        q1.Dequeue();
        q1.Print();
    }

    PriorityQueue q2;
    Item * item = new Item(167);
    q2.Enqueue(new Item(67));
    q2.Enqueue(item);
    q2.Enqueue(new Item(80));
    q2.PriorityEnqueue(new Item(100), item);
    q2.Print();

    while (!(q2.IsEmpty())) {
        q2.Dequeue();
        q2.Print();
    }
    
    return (0);
}