// Code Author : TAVISH CHADHA

// This approach uses 0 additional stacks and Recursion for reversing the given stack.

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack <int>&s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(y);

	return;
}

void reverseStackRec(stack<int>&s)
{
	if(s.empty())
		return;

	int x=s.top();
	s.pop();
	reverseStackRec(s);
	insertAtBottom(s,x);

	return;
}

int main()
{
	// Type your code here.
	stack<int> s;

	for(int i=0;i<=5;i++)
	{
		s.push(i);
	}

	reverseStackRec(s);

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}


	return 0;
}