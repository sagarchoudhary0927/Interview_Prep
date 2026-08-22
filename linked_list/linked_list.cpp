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

     int sizeOfLL = ll.getSize();
     cout << "Size of Linked List is = " << sizeOfLL << endl;

     // Inserting in linked list 

     cout << endl;
     ll.insert_at(-1, 0);
     cout << endl;
     ll.print_linked_list();
     cout << endl;
     sizeOfLL = ll.getSize();
     cout << "Size of Linked List is = " << sizeOfLL << endl;
     cout << endl;
     ll.insert_at(0, 1);
     cout << endl;
     ll.print_linked_list();
     cout << endl;
     sizeOfLL = ll.getSize();
     cout << "Size of Linked List is = " << sizeOfLL << endl;

    ll.insert_at(11, 13);
     cout << endl;
     ll.print_linked_list();
     cout << endl;
     sizeOfLL = ll.getSize();
     cout << "Size of Linked List is = " << sizeOfLL << endl;


     ll.insert_at(12, 15);
     cout << endl;
     ll.print_linked_list();
     cout << endl;
     sizeOfLL = ll.getSize();
     cout << "Size of Linked List is = " << sizeOfLL << endl;

     cout << endl;
     cout << "Index of Eleiment 15 is = " << ll.getPosition(15) << endl;


     cout << endl;
     cout << "Index of Eleiment 20 recursively is = " << ll.getPositionRecursive(20) << endl;
     cout << "Sagar";
     return 0;
}