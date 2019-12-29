#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int* a = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}

		int ans = INT_MIN;
		int* inc = new int[n];
		int* dec = new int[n];

		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				inc[i]=1;
			}
			else if(a[i-1] <= a[i])
			{
				inc[i] = inc[i-1] + 1;
			}
			else
			{
				inc[i] = 1;
			}
		}

		for(int i=n-1;i>=0;i--)
		{
			if(i==n-1)
			{
				dec[i]=1;
			}
			else if(a[i] >= a[i+1])
			{
				dec[i] = dec[i+1] + 1;
			}
			else
			{
				dec[i] = 1;
			}
		}

		for(int i=0;i<n;i++)
		{
			if(ans < inc[i]+dec[i]-1)
			{
				ans = inc[i] + dec[i] - 1; 
			}
		}

		cout << ans << endl;
	}

	return 0;
}
