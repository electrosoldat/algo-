// Code Author : TAVISH CHADHA

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Node
{
public:
	string key;
	T value;

	Node<T>*next;

	//Constructor
	Node(string key, T val)
	{
		this->key = key;
		value = val;
		next = NULL;
	}

	~Node()
	{
		if(next != NULL)
		{
			delete next;
		}
	}
};

template <typename T>
class HashTable
{
	Node <T>** table; // pointer to an array of pointers.
	int cur_size;
	int table_size;

	int hashFn(string key)
	{
		int idx = 0;
		int p = 1;
		for(int j=0; j<key.length(); j++)
		{
			idx = (idx + (key[j]*p))%table_size;
			idx = idx % table_size;
			p = (p*27) % table_size;
		} // 27 as there are 27 characters in a string

		return idx;
	}

	void rehash()
	{
		Node<T>**oldtable = table;
		int oldtableSize = table_size;
		table_size = 2*table_size;
		table = new Node<T>*[table_size];

		for(int i=0;i<table_size;i++)
		{
			table[i] = NULL;
		}

		cur_size = 0;

		// now, shift the elements from the old table to the new table.
		for(int i=0;i<oldtableSize;i++)
		{
			// head of the LL at this location
			Node<T>*temp = oldtable[i];
			while(temp!=NULL)
			{
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			// after the end of this while loop
			// we have traversed one row.
			if(oldtable[i] != NULL)
				delete oldtable[i];
		}
		//delete the table array
		delete [] oldtable;
	}

public:

	T& operator [](string key)
	{
		T* f = search(key);
		if(f == NULL)
		{
			// insert key,value in the hashmap
			T garbage;
			insert(key,garbage);
			f = search(key);
		}

		return *f;
	}

	// constructor
	HashTable(int ts=10)
	{
		table_size = ts;
		table = new Node<T>*[table_size];
		cur_size = 0;

		for(int i=0;i<table_size;i++)
		{
			table[i] = NULL;
		}
	}

	void insert(string key, T value)
	{
		int idx = hashFn(key);
		Node<T>*n = new Node<T>(key,value);
		n->next = table[idx];
		table[idx] = n;
		cur_size++ ;

		// rehash...
	
		float load_factor = cur_size/(1.0*table_size);

		if(load_factor > 0.7)
		{
			rehash();
		}
	}

	void print()
	{
		for(int i=0;i<table_size;i++)
		{
			cout << "Bucket" << i << "->";
			Node<T>*temp = table[i];
			while(temp != NULL)
			{
				cout << temp->key << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key)
	{
		int idx = hashFn(key);
		Node<T>*temp = table[idx];
		while(temp != NULL)
		{
			if(temp->key == key)
			{
				return &temp->value;
			}

			temp = temp->next;
		}
	}

	// erase a node
	void erase(string key)
	{
		int idx = hashFn(key);
		Node<T>* cur = table[idx];
		Node<T>* prev = NULL;
		Node<T>* head = new Node<T>(key,0);
		head->next = cur;		
		prev = head;
		while(cur && cur->key != key)
		{
		    prev = cur;
			cur = cur->next;
		}
		// when equal , come here.
		if(cur)
		{
			prev->next = cur->next;
			table[idx] = head->next;
			return;
		}
	}
};
