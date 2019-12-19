// In this problem, we need to find an element in the array,
// the array is sorted, but rotated.

// I will find the position from which the array can be rotated to get the original array.
// then, i will apply binary search to find the required element.

#include <iostream>
using namespace std;

int binarySearch(int a[],int n,int key)
{
    int s=0;
    int e = n-1;
    int m;
    int ans = -1;
    while(s<=e)
    {
        m = (s+e)/2;
        if(a[m]==key)
        {
            ans = m;
            break;
        }
        else if(key < a[m])
        {
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return ans;
}

void leftrotate(int a[],int n,int k)
{
    for(int i=0;i<k;i++)
    {
        int temp = a[0];
        for(int j=0;j<n-1;j++)
        {
            a[j]=a[j+1];
        }
        a[n-1]=temp;
    }
}
int main() {

    int a[] = {4,5,6,7,8,9,-1,0,1,2,3};
    int n = sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int k; //k is the no. of times, the sorted array has been rotated.
    for(k=0;k<n;k++)
    {
        if(a[k]>a[k+1])
        {
            break;
        }
    }

    // now, left rotate the array k+1 times.
    leftrotate(a,n,k+1);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int key = 0;
    int pos = binarySearch(a,n,key);
    cout << pos;

    return 0;
}
