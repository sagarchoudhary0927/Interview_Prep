#include <iostream>
#include "linked_list_base_class.h"
using namespace std;

// Linked List
int main()
{
    LinkedListBase ll;
    // Prinitng First Node of Linked List
    ll.print_first();
    cout << endl;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0); 
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);

    ll.print_linked_list();
     cout << endl;

    // Prinitng First Node of Linked List
    ll.print_first();
     cout << endl;

     ll.print_last();
     cout << endl;


    cout << "Sagar";
    return 0;
}