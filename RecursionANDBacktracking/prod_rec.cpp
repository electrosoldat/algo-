// Calculate product oftwo numbers without using the '*' operator.

#include <iostream>
#include <cmath>
using namespace std;

int prod(int y, int x)
{
    if(x==1)
        return y;
    int ans = y + prod(y,x-1);
    return ans;
}

int main() {
	// your code goes here
	int a;
	int b;
	cin >> a >> b;
	
	int sign_ans = 1;
    if((a>0 && b >0) || (a<0 && b<0))
        sign_ans = 1;
    else
        sign_ans = -1;
        
    int x = min(abs(a),abs(b));
    int y = max(abs(a),abs(b));
	int ans = prod(y,x);
	cout << ans * sign_ans;
	return 0;
}
