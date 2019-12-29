#include <iostream>
using namespace std;

bool isSorted(int* a, int n)
{
    if(n==1)
    {
        return true;
    }
    bool ans = (a[0] < a[1]) && isSorted(a+1,n-1);
    return ans;
}

int main() {
	// given an array , check whether it is sorted or not 
	
	// it is obvious that one element is always sorted
	int n;
	cin >> n;
	
	int* a = new int[n];
	
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	
	bool ans = isSorted(a,n);
	cout << ans;
	return 0;
}
