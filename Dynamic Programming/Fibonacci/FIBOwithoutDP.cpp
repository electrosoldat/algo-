// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

static int count = 0;

int fib(int n)
{
	count++;
	if(n==0 || n==1)
		return n;

	return fib(n-1) + fib(n-2);
}

int main()
{
	// Type your code here.
	int n;
	cin >> n;

	cout << fib(n) << endl;
	cout << count;

	return 0;
}