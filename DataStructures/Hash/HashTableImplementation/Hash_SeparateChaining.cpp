// Code Author : TAVISH CHADHA

#include <iostream>
//#include "HashTable.h"
#include "operatorOverloadedHash.h"
#include <cstring>
using namespace std;

int main()
{
	// Type your code here.
	HashTable<int> price_menu1;

	price_menu1.insert("Burger",120);
	price_menu1.insert("Pepsi",20);
	price_menu1.insert("BurgerPizza",200);
	price_menu1.insert("Noodles",180);
	price_menu1.insert("Coke",50);
	price_menu1.insert("momos",100);
	price_menu1.insert("Garlic Bread",50);
	price_menu1.insert("Samosa",20);
	price_menu1.insert("Kachori",40);
	price_menu1.insert("Vada PAv",10);
	price_menu1.insert("Pav Bhaji",50);

	price_menu1.print();

	int* price = price_menu1.search("Noodles");
	if(price == NULL)
		cout << "Not Found : " ;
	else
		cout << "Price is : " << *price ;

	price_menu1.erase("Pav Bhaji");
	price_menu1.print();

	price_menu1["Dosa"] = 60;
	price_menu1["Dosa"] += 10;
	cout << price_menu1["Dosa"] << endl;

	return 0;
}