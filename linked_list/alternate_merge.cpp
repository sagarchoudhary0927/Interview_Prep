#include<iostream>
#include "linked_list_base_class.h" 
using namespace std;

LinkedListBase* alternateMerge(Node* h1, Node* h2) {
    LinkedListBase* ans = new LinkedListBase();
    Node *temp1 = h1;
    Node *temp2 = h2;
    
    while (temp1 != nullptr && temp2 != nullptr) {
        // We have to do some work here
        Node *n1 = temp1;
        Node *n2 = temp2;
        ans->push_back(n1->data);
        ans->push_back(n2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr) {
        ans->push_back(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        ans->push_back(temp2->data);
        temp2 = temp2->next;
    }

    return ans;
}

    int main()
    {
        LinkedListBase l1;
        l1.push_back(5);
        l1.push_back(7);
        l1.push_back(17);
        l1.push_back(13);
        l1.push_back(11);
        cout << endl;
        l1.print_linked_list();

        cout << endl;
        LinkedListBase l2;
        l2.push_back(12);
        l2.push_back(10);
        l2.push_back(2);
        l2.push_back(4);
        l2.push_back(6);
        l2.push_back(5);
        l2.push_back(4);
        l2.push_back(3);
        cout << endl;
        l2.print_linked_list();

        cout << endl;

        LinkedListBase *mergedLinkedList = alternateMerge(l1.getHead(), l2.getHead());
        if (mergedLinkedList == nullptr)
        {
            cout << "Merged List is null or empty" << endl;
        }
        mergedLinkedList->print_linked_list();
        return 0;
    }