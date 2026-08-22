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
    ll.push_back(6);
    ll.push_back(7);
    cout << endl;
    ll.print_linked_list();
    cout << "Kth Last element is = " << ll.kthElementFromLast(4) << endl;
}