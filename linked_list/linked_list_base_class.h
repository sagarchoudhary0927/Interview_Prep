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

public:
	LinkedListBase():head(nullptr),tail(nullptr){}


	void push_front(int d) {
		if (head == nullptr) {
			Node* n = new Node(d);
			head = tail = n;
			return;
		} else {
			Node* n = new Node(d);
			n->next = head;
			head = n;
			return;
		}
	}

	void push_back(int d) {
		if (head == nullptr) {
			Node* n = new Node(d);
			head = tail = n;
			return;
		} else {
			Node* n = new Node(d);
			tail->next = n;
			tail = n;
		} 
	}

	void print_linked_list() {
		cout << "------------ Printing Linked List ------------" << endl;
		Node* temp;
		temp = head;
		while (temp->next != nullptr) {
			int data = temp->next->data;
			cout << data << " ";
			temp = temp->next; 
		}

		cout << endl;
		cout << "----------------------------------------------" << endl;
	}

	void print_first() {
		Node* first;
		if (head != nullptr) {
			first = head->next;
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

		}cout << "Tail is Null There isn't any linked list nodes" << endl;
	}


};