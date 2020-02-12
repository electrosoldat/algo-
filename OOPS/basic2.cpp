// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class Car{

private:
	int price;

public: // this is an access modifier.
	int number;
	char *name = NULL;
    const int tyres; // don't initialise tyres here, as all the initialisation must be done inside the constructor.

	// first function should be a constructor.
	Car():name(NULL),tyres(4) // non parameterised constructor
	{
		cout << "Making a car !!" << endl;
	}

	Car(int n,int p,char *name_car):tyres(4) // this is a parameterised constructor.
	{
		number = n;
		price = p;
		int l = strlen(name_car);
		name = new char[l+1];
		strcpy(name,name_car); 
	}
	
	void SetName(const char *n)
	{
		if(name == NULL)
		{
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
		else
		{
			delete name;
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
	}

	// my own copy constructor.
	// to avoid the problem of shallow copy 
	Car(Car &X):tyres(X.tyres)
	{
		cout << "Making a copy of the car" << X.name << endl;
		price = X.price;
		number = X.number;
		int l = strlen(X.name);
		name = new char[l+1];
		strcpy(name,X.name);
	}

	void operator = (Car &X)
	{
		price = X.price;
		number = X.number;
		int l = strlen(X.name);
		name = new char[l+1];
		strcpy(name,X.name);	
	}

	void setPrice(int p) 
	{
		if(p>500)
			price = p;
		else
			price = 500;
	}

	int getPrice() const
	{
		return price;
	}

	void print() const
	{
		cout << name << endl;
		cout << price << endl;
		cout << number << endl;
		cout << tyres << endl;
	}

	// destructor
	~ Car()
	{
		cout << "Destroying the car " << name << endl;
		// write code to delete all the dynamic data members.
		if(name != NULL)
		{
			delete [] name;
		}
	}
};


int main()
{
	// Type your code here.

	Car c;
	c.setPrice(1000);
	c.SetName("BMW");
	c.number = 1993;

	c.print();

	Car d = c;
	d.print();

	d.SetName("Alto");
	// Shallow copy problem.
	c.print();
	d.print();

	Car f(2007,100000,"Porsche");
	f.print();

	Car i;
	i = f;
	i.print();

	// let us create a dynamic car
	Car* DC = new Car(105,5456,"Masserati");
	DC->print();
	delete DC;
	return 0;
}
