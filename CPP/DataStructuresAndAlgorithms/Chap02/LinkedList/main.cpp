#include"list.h"

int main() {
    List * list = new List();

    list->Inset_Head(1);
    list->Inset_Head(2);
    list->Inset_Head(3);
    list->Print_list();
    list->Inset_End(5);
    list->Print_list();
    list->Inset_Before(2, 6);
    list->Print_list();
    list->Inset_After(2, 8);
    list->Print_list();

    std::cout <<list->Count() <<std::endl;

    list->RemoveAll();

    delete list;

    return (0);
}