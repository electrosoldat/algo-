/*

FIND UPPER AND LOWER BOUND
Find position of the last and first occurrence of a given number in a sorted array. If number not exist then print lower and upper bound as -1.

Input Format:
An integer n denoting the size of the array followed by n integers denoting array elements Followed by T testcases Each testcase contains integer x (whose positions are to be found)

Constraints:
Output Format
Lower bound position followed by upper bound position separates by space in each line

Sample Input
5
1 2 3 3 4
3
2
3
10
Sample Output
1 1
2 3
-1 -1

*/

#include <iostream>
using namespace std;

int LowerBound(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    int m;
    int lb = -1;
    while(s<=e)
    {
        m=(s+e)/2;

        if(a[m]==key)
        {
            lb = m;
            e = m-1;
        }
        else if(key<a[m])
        {
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return lb;
}

int UpperBound(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    int m;
    int ub = -1;
    while(s<=e)
    {
        m=(s+e)/2;

        if(a[m]==key)
        {
            ub = m;
            s = m+1;
        }
        else if(key<a[m])
        {
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return ub;
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int t;
    cin >> t;
    while(t--)
    {
        int key;
        cin >> key;
        int ub1 = UpperBound(a,n,key);
        int lb1 = LowerBound(a,n,key);
        cout << lb1 << " " << ub1 << endl;
    }

    return 0;
}
