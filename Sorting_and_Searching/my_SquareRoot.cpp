// Code to find out square root using the binary search approch to calculate the integer part and 
// linear search approach to calculate the fractional part.

#include <iostream>
using namespace std;

double my_sqrt(int n, int p)
{
    int* a = new int(n+1);

    int value=0;
    for(int i=0;i<=n;i++)
    {
        a[i] = value++;
    }

    int s=0;
    int e=n;
    int mid;
    double ans,ans_i,ans_f;
    // 'ans' ek aise no. ko denote kr rha hai, jiska square n se choota hai.

    while(s<=e)
    {
        mid = (s+e)/2;
        int x = mid*mid;
        if(x>n)
        {
            e = mid-1;
        }
        else if(x==n)
        {
            ans_i = mid;
            break;
        }
        else
        {
            ans_i = mid;
            s = mid +1;
        }
    }

    // fractional part ans_f
    ans_f = 0;
    double inc=0.1;
    for(int i=0;i<p;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if((ans_i+ans_f+inc)*(ans_i+ans_f+inc) == n)
            {
                ans_f = ans_f + inc;
                break;
            }
            else if((ans_i+ans_f+inc)*(ans_i+ans_f+inc) < n)
            {
                ans_f = ans_f + inc;
            }
            else
            {
                break;
            }
        }
        inc /= 10;
    }
    
    ans = ans_i + ans_f;
    return ans;
}

int main()
{
    int n,p;
    cin >> n >> p;

    double ans = my_sqrt(n,p);
    cout << ans;

    return 0;
}
