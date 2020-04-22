// Code Author : TAVISH CHADHA

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int minsteps(int n)
{
	int dp_table[100]={0};
	dp_table[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int x, y, z;
		y = INT_MAX;
		z = INT_MAX;
		x = INT_MAX;

		if (i % 2 == 0)
			y = dp_table[i / 2];

		if (i % 3 == 0)
			z = dp_table[i / 3];

		x = dp_table[i - 1];
		int ans = min(x, min(y, z)) + 1;

		dp_table[i] = ans;
	}
	return dp_table[n];
}

int main()
{
	// Type your code here.
	int n;
	cin >> n;

	cout << minsteps(n) << endl;

	return 0;
}