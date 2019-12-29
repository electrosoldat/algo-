// give a number n, return the bit at its ith position.
// Check whether a number is odd/even by using bitwise operators

#include <iostream>
using namespace std;

int getbit(int n,int i)
{
	int bit = ((n & (1 << i)) > 0) ? 1 : 0;
	return bit;
}
int main()
{
	int N;
	cin >> N;
	
	int i;
	cin >> i;
	
	int ans = getbit(N,i);
	cout << ans;
		
	
	return 0;
}
