// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
	vector <int>v;
public:
	bool empty()
	{
		return v.size()==0;
	}
	void push(int data)
	{
		v.push_back(data);
	}
	void pop()
	{
		if(!empty())
			v.pop_back();
	}
	int top()
	{
		return v[v.size()-1];
	}
};

int main()
{
	// Type your code here.
	Stack s;
	for(int i=0;i<=5;i++)
	{
		s.push(i*i);
	}

	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}