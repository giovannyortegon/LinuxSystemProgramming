#include"list.h"

int main() {
    Node * node1;
    Node * node2;

    node1 = new Node(2);
    node2 = new Node(3);

    node1->Next = node2;

    while (node1 != NULL)
    {
        std::cout << node1->Data <<std::endl;
        node1 = node1->Next;
    }

    return (0);
}