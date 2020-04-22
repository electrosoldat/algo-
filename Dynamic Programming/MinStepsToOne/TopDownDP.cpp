// Code Author : TAVISH CHADHA

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int minsteps(int n, int dp_table[])
{
	if (n == 1)
		return 0;
	
	if(dp_table[n]!=0)
		return dp_table[n];

	int z, y, x;
	y = INT_MAX;
	z = INT_MAX;
	x = INT_MAX;


	if (n % 2 == 0)
		y = minsteps(n / 2, dp_table);
	if (n % 3 == 0)
		z = minsteps(n / 3, dp_table);
	x = minsteps(n-1,dp_table);

	if (y && z)
	{
		int ans = min(x, min(y, z)) + 1;
		dp_table[n] = ans;
		return ans;
	}

	else
	{
		if (y)
		{
			int ans = min(x, y) + 1;
			dp_table[n] = ans;
			return ans;
		}
		if (z)
		{
			int ans = min(x, z) + 1;
			dp_table[n] = ans;
			return ans;
		}
		else
		{
			int ans = x;
			dp_table[n] = x;
			return ans;
		}
	}

}

int main()
{
	// Type your code here.
	int n;
	cin >> n;

	int dp_table[1000] = {0};
	cout << minsteps(n, dp_table);

	return 0;
}