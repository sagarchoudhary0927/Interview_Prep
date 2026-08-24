#include <iostream>
#include "linked_list_base_class.h"

int main()
{
    LinkedListBase l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.print_linked_list();

    cout << endl;
    l.kReverseLinkedList(3);
    cout << endl;
    l.print_linked_list();
    return 0;
}