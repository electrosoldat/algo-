// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
	vector <T>v;
public:
	bool empty()
	{
		return v.size()==0;
	}
	void push(T data)
	{
		v.push_back(data);
	}
	void pop()
	{
		if(!empty())
			v.pop_back();
	}
	T top()
	{
		return v[v.size()-1];
	}
};

int main()
{
	// Type your code here.
	Stack<int> s;
	for(int i=0;i<=5;i++)
	{
		s.push(i*i);
	}

	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	Stack<char> c;
	for(int i=65;i<=70;i++)
	{
		c.push(i);
	}

	while(!c.empty())
	{
		cout << c.top() << endl;
		c.pop();
	}

	return 0;
}