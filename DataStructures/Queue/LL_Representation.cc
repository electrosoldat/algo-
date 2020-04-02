// Code Author : TAVISH CHADHA

#include <iostream>
#include <list>
using namespace std;

class Queue
{
	int cursize;
	list<int> qu;
public:

	Queue()
	{
		this->cursize = 0;
	}

	bool isEmpty()
	{
		return this->cursize == 0;
	}

	void Enqueue(int data)
	{
		this->qu.push_back(data);
		this->cursize++ ;
	}

	void Dequeue()
	{
		if(!isEmpty())
		{
			this->cursize -= 1;
			this->qu.pop_front();
		}
	}

	int getFront()
	{
		return this->qu.front();
	}

};

int main()
{
	// Type your code here.
	Queue q;
	for(int i=0;i<=6;i++)
	{
		q.Enqueue(i);
	}

	q.Dequeue();
	q.Enqueue(8);

	while(!q.isEmpty())
	{
		cout << q.getFront() << endl;
		q.Dequeue();
	}

	return 0;
}