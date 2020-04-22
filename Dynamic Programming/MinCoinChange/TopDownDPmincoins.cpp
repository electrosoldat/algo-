// Code Author : TAVISH CHADHA

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int mincoins(int n, int  coins[], int T, int dp_table[])
{
	// Base case
	if (n == 0)
	{
		return 0;
	}

	// Table lookup case
	if (dp_table[n] != 0)
	{
		return dp_table[n];
	}

	// Recursive case
	int ans = INT_MAX;
	for (int i = 0; i < T; i++)
	{
		if (n >= coins[i])
		{
			int subprob = mincoins(n - coins[i], coins, T, dp_table);
			ans = min(ans, subprob) + 1	;
		}
	}

	dp_table[n] = ans;
	return dp_table[n];
}

int main()
{
	// Type your code here.
	int n;
	cin >> n;

	int coins[] = {1, 7, 10};
	int dp_table[100] = {0};

	int T = sizeof(coins) / sizeof(int);

	cout << mincoins(n, coins, T, dp_table);

	return 0;
}