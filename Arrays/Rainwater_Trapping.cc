#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int t; // no. of testcases
	cin >> t;
	
	for(int l=0;l<t;l++)
	{
		int n; // no. of buildings
		cin >> n;
		int* b = new int[n];
		int *left = new int[n];
		int *right = new int[n];
		
		for(int i=0;i<n;i++)
		{
			cin >> b[i]; // inpupt the height of the buildings
		}
		
		// left maximum in the array
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				left[0] = b[0];
			}
			else
			{
				left[i] = max(left[i-1],b[i]);
			}
		}
		
		// right maximum in the array
		for(int i=n-1;i>=0;i--)
		{
			if(i == n-1)
			{
				right[n-1] = b[n-1];
			}
			else
			{
				right[i] = max(right[i+1],b[i]);
			}
		}
		
		int water_ans = 0;
		for(int w=0;w<n;w++)
		{
			int x = min(left[w],right[w]) - b[w];
			water_ans += x;
		}
		
		cout << water_ans << endl;
		
		delete b;
		delete left;
		delete right;
	}
	
	return 0;
}
