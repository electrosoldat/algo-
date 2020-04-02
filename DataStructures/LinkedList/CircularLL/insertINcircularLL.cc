// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	// Constructor
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void pushInCLL(node*&head,int data)
{
	node*ptr1 = new node(data);
	node*temp = head;
	ptr1->next = head;
	if(head != NULL)
	{
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = ptr1;
	}
	else
	{
		ptr1->next = ptr1;
	}

	head = ptr1;
}

int main()
{
	// Type your code here.


	return 0;
}