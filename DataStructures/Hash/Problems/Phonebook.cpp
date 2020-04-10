#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string,vector<string> > phonebook;
	phonebook["Rahul"].push_back("9110182074");
	phonebook["Rahul"].push_back("9999992435");
	phonebook["Rahul"].push_back("6541541054");
	phonebook["Rahul"].push_back("7563110546");
	phonebook["Kajal"].push_back("9654653232");
	phonebook["Kajal"].push_back("3213438798");
	phonebook["Kajal"].push_back("5648648464");

	for(auto p:phonebook)
	{
		cout << "Name " << p.first << "-> ";
		for(string s:p.second)
		{
			cout << s << ", ";
		}
		cout << endl;
	}

	string name;
	cin >> name;
	if(phonebook.count(name)==0)
		cout << "Absent";
	else
	{
		for(string s:phonebook[name])
		{
			cout << s << endl;
		}
	}
}