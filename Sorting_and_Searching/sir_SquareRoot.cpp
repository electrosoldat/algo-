// This code is similar to the my_squareroot code, 
// there is slight difference in the approach use to calculate the fractional part.
// although, the logic is same.

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
    double ans;
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
            ans = mid;
            break;
        }
        else
        {
            ans = mid;
            s = mid +1;
        }
    }

    double inc=0.1;
    for(int i=0;i<p;i++)
    {
        while(ans*ans <= n)
        {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc / 10;
    }
    
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
