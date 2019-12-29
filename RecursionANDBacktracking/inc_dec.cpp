// given a number n, print all numbers from 1 to n and nto 1.

#include <iostream>
using namespace std;

void inc(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {
        inc(n-1);
        cout << n << " ";
    }
}

void dec(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {
        cout << n << " ";
        dec(n-1);
    }
}


int main() {
	// your code goes here
	int n;
	cin >> n;
	inc(n);
	cout << endl;
	dec(n);
	return 0;
}
