// An efficient algorithm to calculate a^b
#include <iostream>
using namespace std;

int my_pow(int a , int b)
{
    if(b==0)
        return 1;
    int ans = a * my_pow(a,b-1);
    return ans;
}

int fastpow(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2 == 0)
    {
        return (fastpow(a,b/2))*(fastpow(a,b/2));
    }
    else
    {
        return a*(fastpow(a,b/2))*(fastpow(a,b/2));
    }
}
int main() {
	// your code goes here
	int a,b;
	cin >> a >> b;
	
	// int ans = my_pow(a,b);
	int ans = fastpow(a,b);
	cout << ans;
	return 0;
}
