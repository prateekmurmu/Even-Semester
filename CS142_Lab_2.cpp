#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node {
public:
	// Data 
	int data;
	// Pointer to the next Node
	Node * next;
	// Construct that makes the ptr to NULL
	Node() {
		next = NULL;
	}

};

class LinkedList {
	// Head + Circles inside linked with each other
public:
	// Head -> Node type ptr
	Node * head;
	Node * tail;

	// Construct
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	// Circles inside linked with each other
	// Rules how circles will be linked

	// Insert
	void insert(int value) {
		// If 1st Node is added
		Node * temp = new Node;
		// Insert value in the node
		temp->data = value;
		// 1st Node only.
		if (head == NULL) {
			head = temp;
		}
		// Any other Node only.
		else {
			tail->next = temp;
		}
		tail = temp;
	}

	void insertAt(int n, int value) {
		// Reach the place before the pos
		

		// Create a node
		Node * temp1 = new Node;

		//set the data field
		temp1->data = value;
		
		//set the link or the next
		temp1->next = NULL;

		//condition if temp1 == head
		if (n == 1)
		{
			temp1->next = head;

			head = temp1;

			return;

		}

		Node * temp2 = head;

			for (int i = 0; i = n - 2; i++)
			{
				temp2 = temp2->next;

			}

		// Moving ptrs like magic ! if not head
		temp1->next = temp2->next;
		temp2->next = temp1;

		// Update the code for 1st position

	}

	void count()
	{
		Node *temp = head;
		int length = 0;
		while (temp != NULL)
		{
			length++;
			temp = temp->next;
		}
		cout << "The number of NODES in the linked list are:- "<< length << endl;
	}

	// Deletion of last element
	void delet() {
		// store the tail in temp
		Node * temp = tail;
		// before tail has to point to null
		Node * current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = NULL;

		// update tail
		tail = current;
		// delete temp
		delete temp;
	}
	// Display
	void display() {
		Node * current = head;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << endl;
	}
};


int main() {
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.delet();
	l1.display();
	l1.insertAt(1, 8);
	l1.display();
	l1.count();
	system("pause");
	return 0;
}