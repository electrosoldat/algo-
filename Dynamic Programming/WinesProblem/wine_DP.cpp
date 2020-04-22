// Code Author : TAVISH CHADHA

#include <iostream>
#include <cmath>
using namespace std;

int max_profit(int wines[], int i, int j, int y, int dp[100][100])
{
	//Base case
	if (i > j)
		return 0;

	// Table Lookup
	if(dp[i][j] != 0)
		return dp[i][j];

	// Recursive case
	int op1 = y * wines[i] + max_profit(wines, i + 1, j, y + 1,dp);
	int op2 = y * wines[j] + max_profit(wines, i, j - 1, y + 1,dp);

	dp[i][j] = max(op1,op2);

	return dp[i][j];
}

int main()
{
	// Type your code here.
	int wines[] = {2, 1, 6, 3, 4};
	int n = sizeof(wines) / sizeof(int);
	int y = 1;
	int dp[100][100] = {0};
	int ans = max_profit(wines, 0, n - 1, y, dp);



	cout << ans;


	return 0;
}