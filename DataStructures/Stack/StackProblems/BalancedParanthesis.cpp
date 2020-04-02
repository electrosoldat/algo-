// Code Author : TAVISH CHADHA

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	// Type your code here.
	stack<char> s;
	for(int i=0;i<s.size();++i)
	{
		// c is the current character in the input string .
		if(c=='(')
			push(c);
		else if(c==')')
		{
			if(s.empty() || s.top()!=')')
				return false;
			s.pop();
		}
	}

	return 0;
}