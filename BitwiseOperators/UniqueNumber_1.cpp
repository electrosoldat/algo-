// PRoblem - given a list of numbers, such that each number occurs twice except one number Fid teh numer that occurs twice.

#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		ans = ans ^ a[i];
	}
	
	cout << ans;
	
	
	return 0;
}
