#include<iostream>
#include "linked_list_base_class.h"
using namespace std;

int main() {
    LinkedListBase ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    cout << endl;
    ll.print_linked_list();

    cout << endl;
    cout << "Reversing the Linked List Now " << endl;
    ll.reverseLinkedList();
    cout << endl;
    ll.print_linked_list();
    cout << endl;
    return 0;
}