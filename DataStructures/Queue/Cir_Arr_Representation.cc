// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class Queue
{
	int front; // pointer to the front of the queue.
	int rear; // pointer to the rear of the queue.
	int max_size; // the maximum no. of elements that can be stored in the queue.
	int cur_size; // the no. of elements present in the queue.
	int* arr; // the array that will store the elements.
public:

	Queue(int default_size = 7)
	{
		this->front = 0;
		this->rear = default_size - 1;
		this->max_size = default_size;
		this->cur_size = 0;
		this->arr = new int[this->max_size];
	}

	bool isFull()
	{
		return this->cur_size == this->max_size;
	}

	bool isEmpty()
	{
		return this->cur_size == 0;
	}

	void Enqueue(int data)
	{
		if(!isFull())
		{
			this->rear = (this->rear + 1) % (this->max_size);
			this->arr[this->rear] = data;
			this->cur_size += 1;
		}
	}

	void Dequeue()
	{
		if(!isEmpty())
		{
			this->front = (this->front + 1) % (this->max_size);
			this->cur_size -= 1;
		}
	}

	int getFront()
	{
		return this->arr[this->front];
	}
};

int main()
{
	// Type your code here.
	Queue q(10);
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