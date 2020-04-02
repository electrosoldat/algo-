// code for cycle detection and removal

bool cycleDetection(node*head)
{
	node*slow = head;
	node*fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;

		if(fast == slow)
		{
			return true;
		}
	}

	return false;
}

node* cycleRemoval(node*head)
{
	node*slow = head;
	node*fast = head;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;

		if(fast == slow)
		{
			break;
		}
	}

	// now , using the Floyd's rule , we can find the starting of the cycle.
	// step - 1 : move the slow pointer to head
	// step - 2 : then move both slow and fast pointers by one postition, until fast==slow.
	slow = head;
	while(slow!=fast)
	{
		slow = slow -> next;
		fast = fast -> next;
	} 

}