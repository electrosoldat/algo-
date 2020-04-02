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
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << temp->data << " -> "; // This step is required to print the data of the last node in the LL.
}

int length(node* head)
{
	int len=0;
	while(head != NULL)
	{
		head = head->next;
		len++ ;
	}
	return len;
}

void insertAtHead(node*&head, int data)
{
	node* n = new node(data); // using Dynamic Memory Allocation so that the data in the LL persists
	n->next = head; // even after the function is terminated.
	head = n;
}

void insertAtTail(node*&head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node* tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new node(data);
	return;
}

void insertInMiddle(node*&head, int data, int p)
{
	if(head == NULL)
	{
		insertAtHead(head,data);
	}
	else if(p > length(head))
	{
		insertAtTail(head,data);
	}
	else
	{
		int jump = 1;
		node* temp = head;
		while(jump <= p-1)
		{
			temp = temp -> next;
			jump++ ;
		}

		node* n = new node(data); // step - 1 : create a new empty node.
		n->next = temp->next; // step - 2 : connect the pointer of the new node.
		temp->next = n; // step - 3 : connect the pointer of the node of the previous position to the new node.
	}
}

void DeleteAtHead(node*&head)
{
	if(head == NULL)
	{
		return;
	}
	node*temp = head;
	head = head->next;
	delete temp;
	return;
}

void DeleteAtTail(node*&head)
{
	node*prev = NULL;
	node*temp = head;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}

void DeleteInMiddle(node*&head,int p)
{
	// first , reach the node just previous to the node to be deleted.
	int jump = 1;
	node*prev = NULL;
	node* temp = head;
	while(jump < p)
	{
		prev = temp;
		temp = temp -> next;
		jump++ ;
	}	

	prev->next = temp->next;
	delete temp;
	return;
}

int main()
{
	// Type your code here.
	node* head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtTail(head,6);
	insertInMiddle(head,2,3);

	printLL(head);
	cout << endl;

	DeleteAtHead(head);
	printLL(head);
	cout << endl;

	DeleteAtTail(head);
	printLL(head);
	cout << endl;

	DeleteInMiddle(head,2);
	printLL(head);
	cout << endl;

	return 0;
}