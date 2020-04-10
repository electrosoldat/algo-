#include <iostream>
using namespace std;
#include <map>
#include <string>

int main()
{
    map<string,int> m;

    // insertion in map
    // Method - 1
    m.insert(make_pair("Mango",100)); 
    // Method - 2
    pair<string,int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);
    // Method - 3
    m["Banana"] = 20;

    // search in a map
    // Method - 1
    string fruit;
    cin >> fruit;
    auto it = m.find(fruit);
    if(it != m.end())
    {
        cout << "Price of " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << fruit << "is not present" << endl;
    }
    // Method - 2
    if(m.count(fruit))
    {
        cout << "Price is " << m[fruit] << endl;
    }
    else
    {
        cout << "Couldn't find " << endl;
    }

    // erase in a map
    m.erase(fruit);

    // update in a map
    m[fruit] += 20;

    // iterate over all the key value pairs.
    m["Litchi"] = 60;
    m["Pineapple"] = 80;

    for(auto it = m.begin();it!=m.end();it++)
    {
        cout << it->first << " and ";
        cout << it->second << endl;
    }

    for(auto p:m)
    {
        cout << p.first << " : " << p.second;
        cout << endl;
    }

    return 0;
}