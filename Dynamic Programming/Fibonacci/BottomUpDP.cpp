// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

static int count=0;

int fib(int n)
{
	count++ ;
	int dp[100] = {0};
	dp[1] = 1;
	for(int i=2;i<=n;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
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