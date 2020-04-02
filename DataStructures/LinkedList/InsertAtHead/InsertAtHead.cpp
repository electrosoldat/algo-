// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	// Constructor for node.
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

/*
class LinkedList
{
	node* head;
	node* tail;
pubic:
	LinkedList()
	{
	head = NULL;
	tail = NULL;
	}	
};
*/

void printLL(node*head)
{
	node* temp = head;
	while(temp->next != NULL)
	{
		cout << temp->data << "-> ";
		temp = temp->next;
	}
	cout << temp->data << "-> "; // This step is required to print the data of the last node in the LL.
}

void insertAtHead(node* &head, int data)
{
	node* n = new node(data); // using Dynamic Memory Allocation so that the data in the LL persists
	n->next = head; // even after the function is terminated.
	head = n;
}

int main()
{
	// Type your code here.
	node* head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);

	printLL(head);
	return 0;
}