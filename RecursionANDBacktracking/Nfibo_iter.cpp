// Code to iteratively calculate the nth fibonacci term

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int ans;
    int ans_n1,ans_n2;
    for(int i=0;i<=n;i++)
    {
        if(i==0 || i==1)
        {
            ans = i;
            ans_n1 = 1;
            ans_n2 = 0;
        }
        else
        {
            ans = ans_n1 + ans_n2;
            ans_n2 = ans_n1;
            ans_n1 = ans;
        }
        
    }
    
    cout << ans;

	return 0;
}
