// set the ith bit to 1
#include <iostream>
using namespace std;

int setbit(int n, int i)
{
	int mask = 1<<i;
	int ans = n | mask;
	return ans;
}

int main()
{
	int n,i;
	cin >> n >> i;
	
	int ans = setbit(n,i);
	cout << ans;

	return 0;
}
