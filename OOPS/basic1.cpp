// Code Author : TAVISH CHADHA

#include <iostream>
#include <cstring>
using namespace std;

class Car{

private:
	int price;

public: // this is an access modifier.
	int number;
	char name[20];

	// first function should be a constructor.
	Car() // non parameterised constructor
	{
		cout << "Making a car !!" << endl;
	}

	Car(int n,int p,char *name_car) // this is a parameterised constructor.
	{
		number = n;
		price = p;
		strcpy(name,name_car);
	}

	/*
	void SetName(char *n)
	{
		if(name == NULL)
		{
			name = new char[strlen(n)+1];
		}
	}*/

	// my own copy constructor.
	Car(Car &X)
	{
		cout << "Making a copy of the car" << X.name << endl;
		price = X.price;
		number = X.number;
		strcpy(name,X.name);
	}

	void setPrice(int p)
	{
		if(p>500)
			price = p;
		else
			price = 500;
	}

	int getPrice()
	{
		return price;
	}

	void print()
	{
		cout << name << endl;
		cout << price << endl;
		cout << number << endl;
	}
};

int main()
{
	// Type your code here.
	
	Car c(1002,10000,"Audi");
	c.print();
	Car d(c);
	c.name[0] = 'W';
	c.print(); // I changed only c, but due to the shallow copy problem , d also changed.
	d.print();

	Car g(1003,34234,"Ferrari");
	g.print();
	
	Car e(g);
	e.print();
}
