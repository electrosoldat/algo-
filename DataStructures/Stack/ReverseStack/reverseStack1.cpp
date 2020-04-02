// Code Author : TAVISH CHADHA

// This approach uses 2 additional stacks for reversing the given stack.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	// Type your code here.
	stack<int> s;
	stack<int> s1;
	stack<int> s2;

	for(int i=0;i<=5;i++)
	{
		s.push(i);
	}

	while(!s.empty())
	{
		int x = s.top();
		s1.push(x);
		s.pop();
	}

	while(!s1.empty())
	{
		int x = s1.top();
		s2.push(x);
		s1.pop();
	}

	while(!s2.empty())
	{
		int x = s2.top();
		s.push(x);
		s2.pop();
	}

	while(!s.empty())
	{
		int x = s.top();
		cout << x << endl;
		s.pop();
	}

	return 0;
}