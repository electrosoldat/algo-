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

void BuildList(node*&head)
{
	int data;
	cin >> data;
	while(data != -1)
	{
		insertAtTail(head,data);
		cin >> data;
	}
}

istream& operator>>(istream &is, node*&head)
{
	BuildList(head);
	return is;
}

ostream& operator<<(ostream &os, node*&head)
{
	printLL(head);
	return os;
}

node* kthFromEnd(node*&head,int k)
{
	// step - 1 : move F, 'k' steps.
	// step - 2 : move S,F ; simultaneously 1 step.

	node* fast = head;
	node* slow = head;
	int jump=1;
	while(jump <= k)
	{
		fast = fast -> next ;
		jump++ ;
	}

	while(fast!=NULL)
	{
		fast = fast -> next;
		slow = slow -> next;
	}

	return slow;

}

node* mergeLLs(node*a,node*b)
{
	// Base case, is when one of the linked list is over.
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	// Recursive case
	node* c;
	if(a->data < b->data)
	{
		c = a;
		c->next = mergeLLs(a->next,b);
	}
	else
	{
		c = b;
		c->next = mergeLLs(a,b->next);	
	}

	return c;
}

node* midpoint(node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	node* slow = head;
	node* fast = head->next;

	while(fast!=NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node* mergeSort(node* head)
{
	// Base case
	if(head == NULL || head->next == NULL)
	{
		return head;
	}

	// Recursive case
	// 1. Mid Point 
	node* mid = midpoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	// 2. Recursively Sort
	a = mergeSort(a);
	b = mergeSort(b);

	// 3. Merge a & b
	node* c = mergeLLs(a,b);
	return c;
}

int main()
{
	// Type your code here.
	node*head = NULL;
	cin >> head;

	cout << head << endl;

	node* head1 = mergeSort(head);
	cout << head1 << endl;

	return 0;
}