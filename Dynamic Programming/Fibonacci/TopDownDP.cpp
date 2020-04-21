// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

static int count=0;

int fib(int n, int dp_table[])
{
	count++ ;
	if(n==0 || n==1)
		return dp_table[n];

	if(dp_table[n]!=0)
	{
		return dp_table[n];
	}

	int ans;
	ans = fib(n-1,dp_table) + fib(n-2,dp_table);
	dp_table[n] = ans;
	return ans;
}

int main()
{
	// Type your code here.

	int n;
	cin >> n;

	int dp_table[100] = {0};
	dp_table[1] = 1;
	cout << fib(n,dp_table) << endl;
	cout << count;

	return 0;
}