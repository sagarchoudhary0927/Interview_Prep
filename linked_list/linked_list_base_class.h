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
    
	// Function gives the position of the Element in the Linked List
	// Positon indexing is based on 1 , 2, 3 , ..... n.
	// -1 means element is not present
	int getPosition(int d) {
		int idx = -1;
		Node *temp = head;
		int count = 1;
		while (temp != nullptr)
		{
			int dataOfNode = temp->data;
			if (dataOfNode == d) {
				idx = count;
				break;
			}
			count = count + 1;
			temp = temp->next;
		}
		return idx;
	}

	int helperSearchRecursive(int d, Node* n, int count) {
		cout << "---------------------" << endl;
		cout << "helperSearchRecursive called for d = " << d << " and count = " << count << endl;
		if (n == nullptr)
		{
			cout << "helperSearchRecursive returning -1 as tail hit" << endl;
			return -1;
		}
		cout << "helperSearchRecursive for node = " << n->data << endl;
		if (n->data == d)
		{
			cout << "helperSearchRecursive as node adat and passed data is same hence returning count = " << count << endl;
			return count;
		}
		count = count + 1;
		return helperSearchRecursive(d, n->next, count);
	}

	int getPositionRecursive(int d) {
		Node *n = head;
		int count = 1;
		return helperSearchRecursive(d, n, count);
	}

	int getFullSizeOfLinkedListInMemory() {
		Node *temp = head;
		int size = 0;
		while (temp != nullptr)
		{
			int d = temp->data;
			size += sizeof(d);
			temp = temp->next;
		}
		return size;
	}

	void pop_first() {
		if (head == nullptr) {
			cout << "No need to delete the node from the first as the Linekd lIts is empty " << endl;
			return;
		}
		Node *n = head;
		Node *nextNode = n->next;
		head = nextNode;
		n = nullptr;
		delete n;
		size--;
		return;
	}

	void pop_last() {
		if (head == nullptr || tail == nullptr) {
			cout << "No need to delete the node from the first as the Linekd lIts is empty " << endl;
			return;
		}
		Node *n = head;
		while (n != nullptr && n->next != tail) {
			n = n->next;
		}
		if (n != nullptr) {
			Node *lastNode = n->next;
			n->next = nullptr;
			tail = n;
			lastNode = nullptr;
			delete lastNode;
			size--;
			return;
		}
	}

	Node* recursiveReverseHelper(Node* n) {
		if (n == nullptr) {
			return nullptr;
		}
		Node *newNode = recursiveReverseHelper(n->next);
		cout << "returning back now " << endl;
		if (newNode == nullptr)
		{
			// It means function has hit the tail and this is the tail
			newNode = new Node(n->data);
			return newNode;
		}
		else
		{
			// Here we have to build the Linked List
			Node *temp = newNode;
			while (temp->next != nullptr)
			{
				temp = temp->next;
				if (temp != nullptr) {
					cout << temp->data << endl;
				}
			}
			temp->next = n;
			n->next = nullptr;
			return newNode;
		}
		return newNode;
	}

	void reverseLinkedList() {
		if (head == nullptr) {
			return;
		}
		head = recursiveReverseHelper(head);
	}
};