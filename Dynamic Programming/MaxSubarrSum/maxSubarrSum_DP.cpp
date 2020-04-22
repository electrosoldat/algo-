// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

int maxSum(int a[],int n)
{
	int dp[100] = {0};
	dp[0] = a[0] > 0 ? a[0] : 0;

	int max_so_far = dp[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = dp[i-1] + a[i];
		if(dp[i] < 0)
			dp[i] = 0;

		max_so_far = max(dp[i],max_so_far);
	}

	return max_so_far;
}

int main()
{
	// Type your code here.
	int a[] = {87,26,65,10,-92,54,64,211,10,87,-95,154};
	int n = sizeof(a)/sizeof(int);

	cout << maxSum(a,n);

	return 0;
}