#include <iostream>
using namespace std;


// Base Node Class Of a Linked List
class Node {
public: 
	int data;
	Node *next;
	Node(int d):data(d),next(nullptr) {}
};


// Base Linked List Class
class LinkedListBase {
	Node *head;
	Node *tail;
	int size;

public:
	LinkedListBase():head(nullptr),tail(nullptr), size(0){}


	void push_front(int d) {
		if (head == nullptr) {
			Node* n = new Node(d);
			head = tail = n;
			size++;
			return;
		} else {
			Node* n = new Node(d);
			n->next = head;
			head = n;
			size++;
			return;
		}
	}

	void push_back(int d) {
		if (head == nullptr) {
			Node* n = new Node(d);
			head = tail = n;
			size++;
			return;
		} else {
			Node* n = new Node(d);
			tail->next = n;
			tail = n;
			size++;
			return;
		} 
	}

	void print_linked_list() {
    cout << "------------ Printing Linked List ------------" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
}

	void print_first() {
		Node* first;
		if (head != nullptr) {
			first = head;
			cout << "First Node of Linked List = " << first->data << endl;
		} else {
			cout << "Head is Null There isn't any linked list nodes" << endl;
		}
	}

	void print_last() {
		Node * last;
		if (tail != nullptr) {
           last = tail;
           cout << "Last Node Of the Linked List = " << last->data << endl;
		} else {
			cout << "Tail is Null There isn't any linked list nodes" << endl;
		}
	}

	int getSize() {
		return this->size;
	}

	void insert_at(int d, int pos) {
		cout << "Now inserting at position = " << pos << " in linked list and the data is = " << d << endl;
		if (pos <= 0 || pos == 1) {
			push_front(d);
			return;
		}  else if (pos > size) {
          push_back(d);
          return;
		} else {
           // Creating the new node first 
			Node* n = new Node(d);
			int count = 1;
			Node* temp = head;
			while (count < pos - 1) {
				temp = temp->next;
				count = count + 1;
			}
			Node* nextNode = temp->next;
			temp->next = n;
			n->next = nextNode;
			size++;
		}
	}


};